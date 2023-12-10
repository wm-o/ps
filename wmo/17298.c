#include <stdio.h>

struct data {
        int num;
        int index;
};

struct data s[1000001];
int a[1000001];
int top;

void push(int num, int index)
{
        s[top].num = num;
        s[top++].index = index;
}

struct data pop(void)
{
        return s[--top];
}

int peek()
{
        return s[top - 1].num;
}

int main()
{
        int n, num;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
                scanf("%d", &num);
                while (top > 0 && peek() < num) {
                        struct data temp = pop();
                        a[temp.index] = num;
                }
                push(num, i);
        }
        while (top) {
                struct data temp = pop();
                a[temp.index] = -1;
        }
        for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
        }
        return 0;
}
