int fib(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fib(n - 1);
}
