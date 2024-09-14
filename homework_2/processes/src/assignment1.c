#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        printf("Child process PID:%d\n", getpid());
        exit(0);
    }
    else
    {
        printf("Parent process PID:%d\n", getpid());
    }

    return 0;
}
