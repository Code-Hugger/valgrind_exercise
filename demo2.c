#include <stdlib.h>

void f(void)
{
     int* x = malloc(10 * sizeof(int));
     x[10] = 0;
}

int main(void)
{
    for(int i = 0; i < 5; i++)
        f();
    return 0;
}