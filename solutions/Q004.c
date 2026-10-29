#include <stdio.h>

void thirdLargest(int arr[],int arr_size)
{
    int first, second, third, i;

    first = second = third = -2147483648;

    for (i = 0; i < arr_size; i++)
    {
        if (arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second)
        {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third && arr[i] != first && arr[i] != second)
        {
            third = arr[i];
        }
    }

    printf("The third Largest element is %d\n", third);
}

int main()
{
    int n, i;
    int arr[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    thirdLargest(arr, n);

    return 0;
}
