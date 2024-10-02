// scene 01

#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("result: %i \n", x + y);
}

// scene 02
#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{

    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("result: %i \n", add(x, y));
}

int add(int a, int b)
{
    return a + b;
}
