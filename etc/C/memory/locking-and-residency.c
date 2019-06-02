/**
 * Experiments with demand paging that shows when allocated pages in memory are
 * became resident.
 *
 * After mlock we guarantee that pages have been placed in physical memory.
 *
 * Futher reading:
 * + TLPI: Ch. 50
 * + Hands On System Programming with Linux: Ch. 4
 *
 * See also:
 * + vmtouch utility: https://github.com/hoytech/vmtouch
 * + sysctl vm.overcommit_* options
 * + RLIMIT_MLOCK (prlimit | grep MEMLOCK) and CAP_IPC_LOCK
 * + grep VmLck /proc/$(pidof name)/status
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

#define NUM_PAGES       64
#define LOCK_PAGE_STEP  10
#define LOCK_PAGE_LEN   4

/* Shows residency of pages via mincore syscall. */
static void display_mincore(char *addr, size_t sz)
{
    int rc;
	long page_size = sysconf(_SC_PAGESIZE);
    long num_pages = (sz + page_size - 1)/page_size;
    unsigned char *vec = malloc(num_pages);

    rc = mincore(addr, sz, vec);
    if (rc == -1) {
        perror("mincore");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < num_pages; j++) {
        if (j % 64 == 0)
            printf("%s%10p: ", (j == 0) ? "" : "\n", addr + (j * page_size));
        printf("%c", (vec[j] & 1) ? '*' : '.');
    }
    printf("\n");

    free(vec);
}

static void display_proc_vmlck(void)
{
    char cmd[256];
    snprintf(cmd, 255, "grep VmLck /proc/%ld/status", (long)getpid());
    system(cmd);
}

int main(int argc, char const* argv[])
{
    char *arr1, *arr2;
    size_t len;
    long step_size, lock_len;
	long page_size = sysconf(_SC_PAGESIZE);

    len = page_size * NUM_PAGES;
    step_size = page_size * LOCK_PAGE_STEP;
    lock_len = page_size * LOCK_PAGE_LEN;

    arr1 = mmap(NULL, len, PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    printf("Before mlock:\n");
    display_mincore(arr1, len);
    display_proc_vmlck();
    printf("\n");

    for (int j = 0; j <= len; j+= step_size) {
        if (mlock(arr1 + j, lock_len) == -1) {
            perror("mlock");
            exit(EXIT_FAILURE);
        }
    }

    printf("After mlock:\n");
    display_mincore(arr1, len);
    display_proc_vmlck();
    printf("\n");

    /* Use MAP_LOCKED flag to lock a memory mapping when it is created. */
    arr2 = mmap(NULL, len, PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS | MAP_LOCKED, -1, 0);
    printf("Mmaped with MAP_LOCKED:\n");
    display_mincore(arr2, len);
    display_proc_vmlck();
    printf("\n");

    /* Lock all pages with mlockall. */
    if (mlockall(MCL_CURRENT) == -1) {
        perror("mlockall");
        exit(EXIT_FAILURE);
    }
    printf("After mlockall:\n");
    display_mincore(arr1, len);
    display_mincore(arr2, len);
    display_proc_vmlck();
    printf("\n");

    exit(EXIT_SUCCESS);
}
