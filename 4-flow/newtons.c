#include <stdio.h>

double apply_newtons(double target, double guess)
{
    return guess - ((guess * guess - target) / (2 * guess));
}

int main()
{
    double t = 612.0;
    double g = 10.0;
    int iter = 5;

    while (iter > 0)
    {
        g = apply_newtons(t, g);
        iter--;
    }

    printf("sqrt(%f) ~ %f", t, g);

    return 0;
}
