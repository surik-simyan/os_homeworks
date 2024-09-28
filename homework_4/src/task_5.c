#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int i, n, min, max;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the grades: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    min = arr[0];
    max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("Highest grade: %d\n", max);
    printf("Lowest grade: %d\n", min);

    free(arr);
    return 0;
}