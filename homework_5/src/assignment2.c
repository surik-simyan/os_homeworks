#include <stdio.h>

struct Data
{
    char a;
    double c;
    int b;
};

int main()
{

    struct Data data;

    printf("Size of struct Data: %lu bytes\n", sizeof(data));

    printf("Address of a: %p\n", &data.a);
    printf("Address of b: %p\n", &data.b);
    printf("Address of c: %p\n", &data.c);
}