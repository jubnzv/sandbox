#include <stdio.h>
#include <stdlib.h>

#include "libexit.h"

static int dummy = 19;

void lexit_init(void) {
    dummy += 1;
    printf("dummy=%d\n", dummy);
    fflush(stdout);
}

void lexit_close(void) {
    dummy += 1;
    printf("dummy=%d\n", dummy);
    fflush(stdout);
}
