#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

void *printFirstHalf(void *array)
{
    int *arr = (int *)array;
    int sum = 0;
    for (int i = 0; i < ARR_SIZE / 2; i++)
    {
        sum = sum + arr[i];
    }
    printf("First half sum is: %d\n", sum);
    pthread_exit(NULL);
}

void *printSecondHalf(void *array)
{
    int *arr = (int *)array;
    int sum = 0;
    for (int i = ARR_SIZE / 2; i < ARR_SIZE; i++)
    {
        sum = sum + arr[i];
    }
    printf("Second half sum is: %d\n", sum);
    pthread_exit(NULL);
}

int main()
{
    srand(time(0));
    pthread_t thread1, thread2;
    int *arr = (int *)malloc(ARR_SIZE * sizeof(int));

    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand() % (100) + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");


    if (pthread_create(&thread1, NULL, printFirstHalf, (void *)arr) != 0)
    {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, printSecondHalf, (void *)arr) != 0)
    {
        perror("Failed to create thread 2");
        return 1;
    }

    if (pthread_join(thread1, NULL) != 0)
    {
        perror("Failed to join thread 1");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0)
    {
        perror("Failed to join thread 2");
        return 1;
    }

    free(arr);
    arr = NULL;

    return 0;
}