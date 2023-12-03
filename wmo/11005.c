#include <stdio.h>

char a[37];

void rec(int num, int b) {
    if (num == 0)
        return ;
    rec(num / b, b);
    printf("%c", a[num % b]);
}

int main() {

    char t = '0'; 
    int i = 0;
    int n, b;

    while (t <= '9') 
        a[i++] = t++;
    t = 'A';
    while (t <= 'Z')
        a[i++] = t++;
    scanf("%d %d", &n, &b);
    rec(n, b);
    return 0;
}
