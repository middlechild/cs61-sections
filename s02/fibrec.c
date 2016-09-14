#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fib(n - 1);
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Usage: ./fib n\n");
        return 0;
    }
    int n = atoi(argv[1]), res = fib(n);
    printf("%d! = %d\n", n, res);
    return 0;
}
