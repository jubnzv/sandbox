#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

#define FPATH_NEW   "./f2.txt"

static FILE* (*fopen_orig)(const char * path, const char * mode) = NULL;

FILE* fopen(const char * path, const char * mode) {
    fopen_orig = dlsym(RTLD_NEXT, "fopen");
    printf("Got it\n");
    return fopen_orig(FPATH_NEW, mode);
}
