#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define Py_IS_FINITE(X) isfinite(X)
#define Py_IS_INFINITY(X) isinf(X)
#define _PyHASH_BITS 61
#define _PyHASH_MODULUS (((size_t)1 << _PyHASH_BITS) - 1)
#define _PyHASH_INF 314159
#define _PyHASH_NAN 0

ssize_t _Py_HashDouble(double v)
{
    int e, sign;
    double m;
    size_t x, y;

    // if (!Py_IS_FINITE(v)) {
    //     if (Py_IS_INFINITY(v))
    //         return v > 0 ? _PyHASH_INF : -_PyHASH_INF;
    //     else
    //         return _PyHASH_NAN;
    // }

    m = frexp(v, &e);

    sign = 1;
    if (m < 0) {
        sign = -1;
        m = -m;
    }

    /* process 28 bits at a time;  this should work well both for binary
       and hexadecimal floating point. */
    x = 0;
    while (m) {
        x = ((x << 28) & _PyHASH_MODULUS) | x >> (_PyHASH_BITS - 28);
        m *= 268435456.0; /* 2**28 */
        e -= 28;
        y = (size_t)m; /* pull out integer part */
        m -= y;
        x += y;
        if (x >= _PyHASH_MODULUS)
            x -= _PyHASH_MODULUS;
    }

    /* adjust for the exponent;  first reduce it modulo _PyHASH_BITS */
    e = e >= 0 ? e % _PyHASH_BITS
               : _PyHASH_BITS - 1 - ((-1 - e) % _PyHASH_BITS);
    x = ((x << e) & _PyHASH_MODULUS) | x >> (_PyHASH_BITS - e);

    x = x * sign;
    if (x == (size_t)-1)
        x = (size_t)-2;

    return (ssize_t)x;
}

int main(int argc, char *argv[])
{
    printf("_PyHASH_MODULUS=%lld\n", _PyHASH_MODULUS);
    printf("%lld\n", _Py_HashDouble(atof(argv[1])));
    return 0;
}
