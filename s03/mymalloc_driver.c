#include <stdio.h>
#include <string.h>
#include "mymalloc.h"

int main() {
    printf("Our current size is %zu.\n", mymalloc_heap_size());

    char* str = (char*) mymalloc(sizeof("I can haz string memory, yay!\0"));
    strcpy(str, "I can haz string memory, yay!");

    printf("%s\n", str);

    printf("Header size is %zu.\n", mymalloc_allocation_overhead());
    printf("String size is %zd.\n", strlen(str) + 1);
    printf("Our current size is %zd.\n", mymalloc_heap_size());

    printf("Check #1: %s\n", (mymalloc_heap_size() >= strlen(str) + 1) ? "[[32mPASS[0m]" : "[[31mFAIL[0m] (Size appears unimplemented)");

    char* c1 = (char*) mymalloc(1024*1024);
    size_t s1 = mymalloc_heap_size();
    myfree(c1);
    printf("Our current free space is %zd.\n", mymalloc_free_space());

    size_t free_space = mymalloc_free_space();
    printf("Check #2: %s\n", (free_space >= 1024*1024 && free_space < 1024*1024 + 64) ? "[[32mPASS[0m]" : "[[31mFAIL[0m] (Free/free_space appear unimplemented)");

    char* c2 = (char*) mymalloc(1023*1024);
    size_t s2 = mymalloc_heap_size();
    printf("Check #3: %s\n", (c1 == c2 && s1 == s2 && s2 != 0) ? "[[32mPASS[0m]" : "[[31mFAIL[0m] (Malloc should use freed memory whenever possible)");

    c1 = (char*) mymalloc(512);
    size_t s3 = mymalloc_heap_size();
    myfree(c1);
    printf("Check #4: %s\n", (s2 == s3 && s2 != 0) ?  "[[32mPASS[0m]" : "[[31mFAIL[0m] (Malloc should split free chunks)");

    char* c3 = (char*) mymalloc(512*1024);
    size_t s4 = mymalloc_heap_size();
    // This allocation should cause `c2` to split.
    myfree(c2);
    c1 = (char*) mymalloc(256*1024);
    // These frees should coalesce `c2` and `c3` into an enormous free region.
    myfree(c1);
    myfree(c3);
    // This allocation should use that free region.
    c1 = (char*) mymalloc(1280*1024);
    size_t s5 = mymalloc_heap_size();

    printf("Check #5: %s\n", (s4 == s5 && s4 != 0) ? "[[32mPASS[0m]" : "[[31mFAIL[0m] (Free should coalesce free blocks)");

    return 0;
}
