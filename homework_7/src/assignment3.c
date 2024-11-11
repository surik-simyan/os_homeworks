#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printThreadInfo(void *thread_id)
{
    int *id = (int *)thread_id;
    for (int i = 0; i < 5; i++)
    {
        printf("Thread id: %d Num: %d\n", *id, i);
    }
    free(id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2, thread3;

    int *first = malloc(sizeof(int));
    int *second = malloc(sizeof(int));
    int *third = malloc(sizeof(int));

    if (first == NULL || second == NULL || third == NULL)
    {
        printf("Error allocating memory\n");
        exit(-1);
    }

    *first = 1;
    *second = 2;
    *third = 3;

    if (pthread_create(&thread1, NULL, printThreadInfo, (void *)first) != 0)
    {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, printThreadInfo, (void *)second) != 0)
    {
        perror("Failed to create thread 2");
        return 1;
    }

    if (pthread_create(&thread3, NULL, printThreadInfo, (void *)third) != 0)
    {
        perror("Failed to create thread 3");
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

    if (pthread_join(thread3, NULL) != 0)
    {
        perror("Failed to join thread 3");
        return 1;
    }

    return 0;
}