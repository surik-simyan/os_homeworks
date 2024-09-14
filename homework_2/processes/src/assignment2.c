#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{

    pid_t pid1, pid2;
    int status1, status2;

    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
    }
    else if (pid1 == 0)
    {
        printf("First child process PID:%d\n", getpid());
        exit(0);
    }
    else
    {
        pid2 = fork();
        if (pid2 == -1)
        {
            perror("fork");
        }
        else if (pid2 == 0)
        {
            printf("Second child process PID:%d\n", getpid());
            exit(0);
        }
        else
        {
            waitpid(pid2, &status2, 0);
            printf("Second child finished with status %d\n", status2);

            wait(&status1);
            printf("First child finished with status %d\n", status1);

            printf("Parent process PID: %d\n", getpid());
        }
    }

    return 0;
}
