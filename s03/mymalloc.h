#ifndef MYMALLOC_H
#define MYMALLOC_H
#include <stddef.h>

void* mymalloc(size_t sz);
void myfree(void* ptr);

size_t mymalloc_heap_size(void);
size_t mymalloc_free_space(void);
size_t mymalloc_allocation_overhead(void);

#endif
