#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void insertion_sort(int *arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertion_sort(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}