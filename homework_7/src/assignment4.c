#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

void *printSquare(void *num)
{
    int *n = (int *)num;
    printf("Num: %d | Square: %d\n",*n, *n * *n);
    pthread_exit(NULL);
}

int main()
{
    srand(time(0));
    pthread_t threads[ARR_SIZE];
    int *arr = (int *)malloc(ARR_SIZE * sizeof(int));

    printf("Array: ");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand() % (100) + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (pthread_create(&threads[i], NULL, printSquare, &arr[i]) != 0)
        {
            perror("Failed to create thread 1");
            return 1;
        }
    }

    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread 1");
            return 1;
        }
    }

    free(arr);
    arr = NULL;

    return 0;
}