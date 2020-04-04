#include <stdio.h>
#include <assert.h>
#include <libgen.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/// @brief Test if path is a directory
/// @return
///   0 - path exists but it is not a directory
///   1 - path exists and it is a directory
/// < 0 - error
static int path_is_dir(const char *path)
{
	struct stat st;
	int ret;

	ret = stat(path, &st);
	if (ret < 0)
		return -errno;

	return !!S_ISDIR(st.st_mode);
}

/// @brief Check that current user can create file
static int check_permissions(const char *path) {
    if (path == NULL) {
        errno = EINVAL;
        return -1;
    }

    char *d  = strdup(path);
    char *dir = dirname(d);
    if (path_is_dir(dir) != 1) {
        errno = EINVAL;
        return -1;
    }
    if (access(dir, W_OK) == -1) {
        return -1;
    }

    return 0;
}

int main(int argc, char const* argv[])
{
    const char *p1 = "/usr/lib/1.txt";
    assert(check_permissions(p1) == -1);

    const char *p2 = "/home/jubnzv/1.txt";
    assert(check_permissions(p2) == 0);

    return 0;
}
