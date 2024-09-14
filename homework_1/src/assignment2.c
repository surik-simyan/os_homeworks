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
        execl("/usr/bin/ls", "ls", NULL);
        perror("execl");
        return 1;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        sleep(1);
        execl("/usr/bin/date", "date", NULL);
        perror("execl");
        return 1;
    }
    else
    {
        sleep(2);
        printf("Parent process done\n");
    }

    return 0;
}
