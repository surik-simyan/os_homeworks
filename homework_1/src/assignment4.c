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
        execl("/usr/bin/grep", "grep", "ipsum", "../src/text.txt", "--color=auto", NULL);
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
