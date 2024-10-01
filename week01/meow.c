#include <stdio.h>

// way 1
int main(void)
{
    int counter = 3;

    while (counter > 0)
    {
        printf("meow\n");
        counter--;
    }
}


// way 2
int main2(void)
{
    int counter = 1;

    while (counter <= 3)
    {
        printf("meow\n");
        counter++;
    }
}
