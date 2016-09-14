#include <stdio.h>

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Usage: ./fib n\n");
        return 0;
    }
    int n = atoi(argv[1]), res = 1;
    for (int i = 1; i < n; i++) {
        res *= i;
    }
    printf("%d! = %d\n", n, res);
    return 0;
}
