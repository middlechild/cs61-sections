#include <stdlib.h>
#include <stdio.h>

int main() {
    int* ptr1 = malloc(sizeof(int));
    int* ptr2 = malloc(sizeof(int));
    free(ptr1);
    free(ptr1);
}
