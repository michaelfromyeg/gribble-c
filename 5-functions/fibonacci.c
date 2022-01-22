#include <stdio.h>
#include <stdlib.h>

// Converted to <long long> to mitigate overflow for large <n>!
long long fib(int n);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: ./fibonacci <n>");
        return 1;
    }

    int n = atoi(argv[1]);

    printf("fib(%d)=%lld\n", n, fib(n));
    return 0;
}

long long fib(int n)
{
    long long x1 = 0;
    long long x2 = 1;

    for (int i = 0; i < n; i++)
    {
        long long t = x2;
        x2 = x1 + x2;
        x1 = t;

        // printf("x1 = %d, x2 = %d\n", x1, x2);
    }

    return x1;
}
