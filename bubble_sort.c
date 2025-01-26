#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
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
    bubble_sort(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}