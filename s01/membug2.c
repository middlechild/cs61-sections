#include <stdlib.h>
#include <stdio.h>

int main() {
    while (1) {
        if (malloc(1000000) == NULL) {
            printf("out of memory\n");
            abort();
        }
    }
}
