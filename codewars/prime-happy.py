'''
https://www.codewars.com/kata/prime-happy

A number `n` is called `prime happy` if there is at least one prime less than `n` and the `sum of all primes less than n` is evenly divisible by `n`. Write `isPrimeHappy(n)` which returns `true` if `n` is `prime happy` else `false`.
'''
def primes_gen(m):
    for n in xrange(2, m):
        if all([True if (n % i) != 0 else False for i in xrange(2, n-1)]):
            yield n

def is_prime_happy(n):
    return True if n > 2 and sum([p for p in primes_gen(n)]) % n == 0 else False


if __name__ == '__main__':
    print(is_prime_happy(5))
    print(is_prime_happy(8))
