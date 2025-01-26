#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void merge(int *arr, int low, int mid, int high)
{
    int temp[MAX];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    for (int i = 0; i < k; i++)
    {
        arr[low + i] = temp[i];
    }
}

void merge_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n = 0;
    int x = 0;
    int arr[MAX];
    while (scanf("%d", &x) == 1)
    {
        arr[n++] = x;
    }
    merge_sort(arr, 0, n - 1);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}