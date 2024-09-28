#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int i, n = 10;

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    arr = (int *)realloc(arr, (n / 2) * sizeof(int));

    printf("Updated array: ");
    for (i = 0; i < (n / 2); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}