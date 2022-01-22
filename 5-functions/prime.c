#include <stdio.h>

int isprime(int n);
void nprimes(int n);

int main(int argc, char *argv[])
{
    printf("isprime(%d)=%d\n", 12, isprime(12));
    printf("isprime(%d)=%d\n", 17, isprime(17));

    nprimes(1000);

    return 0;
}

int isprime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void nprimes(int n)
{
    int i = 1;
    int counter = 0;

    while (counter < 1000)
    {
        if (isprime(i))
        {
            printf("i=%d\n", i);
            counter++;
        }
        i++;
    }
}
