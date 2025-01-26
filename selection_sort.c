#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void selection_sort(int *arr, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        if (minindex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
        }
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
    selection_sort(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}