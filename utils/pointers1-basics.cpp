#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 10;
    int *p = &a;
    int **q = &p;

    **q = *p + 7;

    printf("p -> address of a: %d\n", p);
    printf("*p -> value of a: %d\n", *p);
    printf("*q is equals to p -> address of a: %d\n", *q);
    printf("**q is equals to *p -> value of a: %d\n", **q);

    return 0;
}
