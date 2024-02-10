#include <stdio.h>

int is_palindrome(char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    char s[100];
    printf("Enter a string:");
    gets(s);
    printf("%s is %s palindrome\n",s, is_palindrome(s) ? "" : "not");
}