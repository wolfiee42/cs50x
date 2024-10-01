#include <stdio.h>

// way 1 - while loop
int main(void)
{
    int counter = 3;

    while (counter > 0)
    {
        printf("meow\n");
        counter--;
    }
}

// way 2 - while loop
int main2(void)
{
    int counter = 1;

    while (counter <= 3)
    {
        printf("meow\n");
        counter++;
    }
}

// way 3 - for loop
int main3(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }
}