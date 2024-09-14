#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>

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
        execl("/usr/bin/echo", "echo", "Hello from the child process", NULL);
        perror("execl");
        return 1;
    }
    else
    {
        sleep(1);
        printf("Parent process done\n");
    }

    return 0;
}
