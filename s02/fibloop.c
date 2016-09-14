#include <stdio.h>

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Usage: ./fib n\n");
        return 0;
    }
    int res = 1;
    for (int i = 1; i < n; i++) {
        res *= i;
    }
    printf("%d! = %d\n", argv[1], res);
    return 0;
}
