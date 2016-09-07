#include <stdlib.h>
#include <stdio.h>

int main() {
    int* ptr1 = malloc(3 * sizeof(int));
    free(ptr1);
    printf("ptr1 = %p\n", ptr1);
    *ptr1 = 1;
    printf("*ptr1 = %d\n", *ptr1);

    int* ptr2;
    printf("ptr2 = %p\n", ptr2);
    *ptr2 = 2;
    printf("*ptr2 = %d\n", *ptr2);
}
