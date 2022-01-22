#include <stdio.h>

double to_celsius(double farenheit)
{
    return (farenheit - 32.0) / 1.8;
}

int main()
{
    double c = to_celsius(27);

    printf("27 deg F = %f deg C", c);

    return 0;
}
