#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// 1
int main(void)
{
    string s = get_string("s: ");
    string t = s;

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);
}
