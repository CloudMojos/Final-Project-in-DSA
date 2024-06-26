#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 1, y = 2;
    swap(&x, &y);
    printf("x is: %d, y is: %d\n", x, y);
}
