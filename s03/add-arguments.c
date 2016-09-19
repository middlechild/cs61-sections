int add(int a, int b) __attribute__((noinline));
int add(int a, int b) {
    return a + b;
}

int main() {
    return add(1, 2);
}
