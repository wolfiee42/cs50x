#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("what is your name? ");
    printf("Hello, %s\n", answer);
}
