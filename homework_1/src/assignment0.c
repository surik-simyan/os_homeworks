#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t pid1 = fork();
    if (pid1 < 0)
        perror("Fork #1 failed");

    pid_t pid2 = fork();
    if (pid2 < 0)
        perror("Fork #2 failed");

    pid_t pid3 = fork();
    if (pid3 < 0)
        perror("Fork #3 failed");

    return 0;
}