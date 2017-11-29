'''
https://www.codewars.com/kata/the-fibfusc-function-part-1

The `fibfusc` function is defined recursively as follows:

    fibfusc(0) = (1, 0)
    fibfusc(1) = (0, 1)
    fibfusc(2n) = ((x + y)(x - y), y(2x + 3y)), where (x, y) = fibfusc(n)
    fibfusc(2n + 1) = (-y(2x + 3y), (x + 2y)(x + 4y)), where (x, y) = fibfusc(n)

Your job is to produce the code for the `fibfusc` function. In this kata, your function will be tested with small values of n, so you should not need to be concerned about stack overflow or timeouts.

When done, move on to [Part 2](http://www.codewars.com/kata/the-fibfusc-function-part-2).

'''
def fibfusc(n):
    if n == 0:
        return (1, 0)
    if n == 1:
        return (0, 1)

    if not n % 2:  # fibfusc(2n)
        x, y = fibfusc(n/2)
        return ((x + y) * (x - y), y * (2 * x + 3 * y))
    else:  # fibfusc(2n + 1)
        x, y = fibfusc(n/2)
        return (-1 * y * (2 * x + 3 * y), (x + 2 * y) * (x + 4 * y))

if __name__ == '__main__':
    print(fibfusc(0))
    print(fibfusc(1))
    print(fibfusc(2))
    print(fibfusc(3))
    print(fibfusc(4))
    print(fibfusc(5))
