#include <stdio.h>
#include <string.h>

char s[100];
int n;

int get_num(char c) 
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

int main() 
{
    int result = 0;
    int base = 0;

    scanf("%s %d", s, &base);
    n = 1;
    int len = strlen(s);
    while (s[--len]) {
        result += n * get_num(s[len]);
        n = n * base;
    }
    printf("%d\n", result);
    return 0;
}
