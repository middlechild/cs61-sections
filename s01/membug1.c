#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main() {
    void* ptr = malloc(2001);
    free((char*) ptr + 100);
}
