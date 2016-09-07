#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LEFT(x)  (2 * (x) + 1)
#define RIGHT(x) (2 * (x) + 2)

typedef struct heap {
    int* array;
    int size;
} heap;

void heap_max_heapify_from(heap* h, int i) {
    int size = h->size;
    int* a = h->array;

    int largest = i;
    int l = LEFT(i);
    if (l <= size && a[l] > a[largest])
        largest = l;
    int r = RIGHT(i);
    if (r <= size && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        int tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        heap_max_heapify_from(h, largest);
    }
}

void heap_max_heapify(heap* h) {
    int i = h->size / 2 - 1;
    for (; i >= 0; --i)
        heap_max_heapify_from(h, i);
}

heap* heap_init_from_args(int argc, char* argv[]) {
    heap* new_heap = (heap*) malloc(sizeof(heap));
    memset(new_heap, 0, sizeof(*new_heap));
    // allocate some space for array items
    int array_capacity = 8;
    new_heap->array = (int*) malloc(array_capacity);

    int size = 0;
    int k;
    for (int i = 1; i < argc; i++) {
        if (sscanf(argv[i], "%d", &k)) {
            if (size >= array_capacity) {
                // This is the "vector pattern" from C Patterns (CS61 wiki)!
                array_capacity *= 2;
                realloc(new_heap->array, array_capacity);
            }
            new_heap->array[size] = k;
            ++size;
        }
    }

    new_heap->size = size;
    return new_heap;
}

void heap_print(heap* h) {
    int next_row = 1;
    for (int i = 0; i < h->size; ++i) {
        if (i == next_row) {
            printf("\n");
            next_row = LEFT(next_row);
        }
        printf("%d  ", h->array[i]);
    }
    printf("\n");
}

void heap_free(heap* h) {
    free(h->array);
    free(h);
}

int main(int argc, char* argv[]){
    if (argc == 1) {
        printf("Usage: ./heap #1 #2 ...\n");
        return 0;
    }

    heap* h = heap_init_from_args(argc, argv);
    heap_max_heapify(h);
    heap_print(h);
    heap_free((heap*) &h);
    return 0;
}
