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

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2
int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }
    strcpy(t, s);
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);
    return 0;
}
