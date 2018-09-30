// https://www.codewars.com/kata/57a1d5ef7cb1f3db590002af/

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}
