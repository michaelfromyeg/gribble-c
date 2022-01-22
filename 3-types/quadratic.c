#include <stdio.h>
#include <math.h>

typedef struct
{
    float left, right;
} Roots;

Roots find_roots(double a, double b, double c)
{
    Roots r;
    r.left = (-b - sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
    r.right = (-b + sqrt(b * b - 4.0 * a * c)) / (2.0 * a);

    return r;
}

int main()
{
    Roots r = find_roots(1.2, 2.3, -3.4);
    printf("left = %f\n", r.left);
    printf("right = %f\n", r.right);

    return 0;
}
