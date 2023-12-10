#include <stdio.h>

int arr[100001];
int a[100001];

void merge(int left, int mid, int right)
{
        int i = left, j = mid + 1, k = left;
        int tmp[100001];

        while (i <= mid && j <= right) {
                if (arr[i] <= arr[j]) {
                        tmp[k++] = arr[i++];
                } else {
                        tmp[k++] = arr[j++];
                }
        }

        while (i <= mid) {
                tmp[k++] = arr[i++];
        }

        while (j <= right) {
                tmp[k++] = arr[j++];
        }

        for (int i = left; i <= right; i++) {
                arr[i] = tmp[i];
        }
}

void merge_sort(int left, int right) 
{
        if (left < right) {
                int mid = (left + right) / 2;
                merge_sort(left, mid);
                merge_sort(mid + 1, right);
                merge(left, mid, right);
        }
}

void b_search(int start, int end, int target)
{
        int mid = (start + end) / 2;

        if (start > end) {
                printf("0\n");
                return;
        }
        if (arr[mid] == target) {
                printf("1\n");
                return ;
        }
        if (arr[mid] < target) {
                b_search(mid + 1, end, target);
        } else {
                b_search(start, mid - 1, target);
        }
}

int main()
{
        int n, m, num;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
        }
        merge_sort(0, n - 1);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
                scanf("%d", &num);
                b_search(0, n - 1, num);
        }
        return 0;
}
