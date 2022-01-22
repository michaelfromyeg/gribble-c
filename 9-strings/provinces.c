#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lower(char *);

int main(int argc, char *argv[])
{
    char *provinces[] = {"British Columbia", "Alberta", "Saskatchewan",
                         "Manitoba", "Ontario", "Quebec", "New Brunswick",
                         "Nova Scotia", "Prince Edward Island", "Newfoundland",
                         "Yukon", "Northwest Territories", "Nunavut"};

    for (int i = 0; i < 13; i++)
    {
        char *pl = lower(provinces[i]);
        printf("provinces[%d] = %s\n", i, pl);
        free(pl);
    }
    return 0;
}

char *lower(char *s)
{
    char *l = malloc(strlen(s) + 1);
    l[strlen(s)] = '\0'; // is this needed?

    for (int i = 0; i < strlen(s); i++)
    {
        l[i] = s[i] >= 'a' && s[i] <= 'z' ? s[i] - 32 : s[i];
    }

    return l;
}
