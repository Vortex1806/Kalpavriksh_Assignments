#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(arr, i, j);
    }
    swap(arr, low, j);
    return j;
}

void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
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
    quick_sort(arr, 0, n - 1);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}