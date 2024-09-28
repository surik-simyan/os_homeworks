#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **arr;
    int i, n = 3, string_size = 50;

    arr = (char **)malloc(n * sizeof(char *));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(string_size * sizeof(char));
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("Enter %d strings: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    arr = (char **)realloc(arr, (n + 2) * sizeof(char *));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = n; i < n + 2; i++)
    {
        arr[i] = (char *)malloc(string_size * sizeof(char));
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("Enter 2 more strings: ");
    for (i = n; i < n + 2; i++)
    {
        scanf("%s", arr[i]);
    }

    printf("All strings: ");
    for (i = 0; i < n + 2; i++)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}