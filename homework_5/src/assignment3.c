#include <stdio.h>

#pragma pack(1)
struct Data
{
    char a;
    int b;
    double c;
};

int main()
{

    struct Data data;

    printf("Size of struct Data: %lu bytes\n", sizeof(data));

    printf("Address of a: %p\n", &data.a);
    printf("Address of b: %p\n", &data.b);
    printf("Address of c: %p\n", &data.c);
}