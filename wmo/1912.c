#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int d[100001];
int a[100001];

int main() {
    int n, max;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    d[0] = a[0];
    max = d[0];
    for (int i = 1; i < n; i++) {
        d[i] = MAX(d[i - 1] + a[i], a[i]);
        if (max < d[i])
            max = d[i];
    }
    printf("%d\n", max);
    return 0;
}
