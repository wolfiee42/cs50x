#include <stdio.h>
#include <cs50.h>

// 1
int main(void)
{
    int i = get_int("i: ");
    int j = get_int("j: ");

    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different.\n");
    }
}

#include <stdio.h>
#include <cs50.h>
#include <string.h>

// 2
int main(void)
{
    char *i = get_string("i: ");
    char *j = get_string("j: ");

    if (strcmp(i, j) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different.\n");
    }
}

#include <stdio.h>
#include <cs50.h>
#include <string.h>

// 3
int main(void)
{
    char *i = get_string("i: ");
    char *j = get_string("j: ");

    printf("%p\n", i);
    printf("%p\n", j);
}
