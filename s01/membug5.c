#include <stdlib.h>
#include <stdio.h>

int main() {
    int* array = (int*) malloc(10);
    for (int i = 0; i <= 10; ++i)
        array[i] = 1;
    free(array);
}
