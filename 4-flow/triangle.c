#include <stdio.h>

void print_layer(int layer, int max)
{
    int tot = 2 * max - 1;
    int now = 2 * layer - 1;

    for (int i = 0; i < (tot - now) / 2; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < now; i++)
    {
        printf("*");
    }

    printf("\n");
}

int main()
{
    int iter = 6;
    int layer = 1;

    while (layer <= iter)
    {
        print_layer(layer, iter);
        layer++;
    }

    return 0;
}
