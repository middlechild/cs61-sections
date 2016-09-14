#include <stdio.h>
#include "helper.c"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./fib n\n");
        return 0;
    }
    int n = atoi(argv[1]), res = fib(n);
    printf("%d! = %d\n", n, res);
    return 0;
}
