#include <stdio.h>
#include <stdlib.h>

void first_out(void)
{
    printf("Message from first function!\n");
}

void second_out(void)
{
    printf("Message from second function!\n");
}

int main()
{
    if (atexit(first_out))
    {
        fprintf(stderr, "atexit() failed!\n");
    }

    if (atexit(second_out))
    {
        fprintf(stderr, "atexit() failed!\n");
    }

    // Exiting the program with exit
    // exit(0);

    printf("Exiting!\n");

    return 0;
}