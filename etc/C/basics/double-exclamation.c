// double-exclamation.c: In function ‘f’:
// double-exclamation.c:1:24: warning: returning ‘int *’ from a function with
// return type ‘int’ makes integer from pointer without a cast
// [-Wint-conversion] int f(int *a) { return a; }

// double-exclamation.c: In function ‘f’:
// double-exclamation.c:5:24: warning: cast from pointer to integer of different
// size [-Wpointer-to-int-cast] int f(int *a) { return (int)a; }

int f(int *a) { return !!a; }

int main()
{
    int a = 42;
    f(&a);
    return 0;
}
