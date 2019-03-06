#include	"unpipc.h"

#define	FILE	"test.data"
#define	SIZE	32768

int
main(int argc, char **argv)
{
	int		fd, i;
	char	*ptr;

		/* 4open: create or truncate; then mmap file */
	fd = Open(FILE, O_RDWR | O_CREAT | O_TRUNC, FILE_MODE);
	ptr = Mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	for (i = 4096; i <= SIZE; i += 4096) {
		printf("setting file size to %d\n", i);
		Ftruncate(fd, i);
		printf("ptr[%d] = %d\n", i-1, ptr[i-1]);
	}


    /* If the file previously was larger than this size, the extra data is lost.
     * If the file previously was shorter, it is extended, and the extended part
     * reads as null bytes ('\0'). */
    printf("setting file size to %d\n", i);
    Ftruncate(fd, i);
    printf("ptr[%d] = %d\n", i-1, ptr[i-1]);

	exit(0);
}
