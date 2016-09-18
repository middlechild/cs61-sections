#include "mymalloc.h"
#include <unistd.h>
#include <assert.h>

typedef struct memblock_header {
    size_t size;
    int free;
    struct memblock_header* next;
    struct memblock_header* prev;
} memblock_header;

typedef struct memblock_trailer {
    size_t size;
} memblock_trailer;

#define MEMBLOCK_ALIGNMENT 64

static void* heap_base = NULL;

static void* header_to_data(memblock_header* hdr);
static memblock_header* data_to_header(void* data);
static memblock_trailer* header_to_trailer(memblock_header* hdr);
static memblock_header* following_header(memblock_header* hdr);
static memblock_header* previous_header(memblock_header* hdr);

static memblock_header* free_list = NULL;
static void free_list_insert_after(memblock_header* hdr, memblock_header* prev);
static void free_list_remove(memblock_header* hdr);

void* mymalloc(size_t sz) {
    // Ensure that memblock_header is a multiple of 8 bytes
    // (for alignment purposes).
    assert(sizeof(memblock_header) % 8 == 0);

    // Add space for a memblock_header.
    sz += sizeof(memblock_header) + sizeof(memblock_trailer);

    // Ensure `sz` is a multiple of MEMBLOCK_ALIGNMENT.
    if (sz % MEMBLOCK_ALIGNMENT != 0)
        sz += MEMBLOCK_ALIGNMENT - (sz % MEMBLOCK_ALIGNMENT);

    // Look for the perfect block.
    for (memblock_header* cur = free_list; cur; cur = cur->next) {
        if (cur->size == sz) {
            free_list_remove(cur);
            return header_to_data(cur);
        }
    }

    // Look for the best alternate block.
    memblock_header *best = NULL;
    for (memblock_header* cur = free_list; cur; cur = cur->next) {
        if (cur->size > sz) {
          if (best && best->size < cur->size)
            continue;
          best = cur;
        }
    }
    if (best) {
      size_t old_sz = best->size;
      best->size = sz;
      header_to_trailer(best)->size = sz;
      following_header(best)->size = old_sz - sz;
      header_to_trailer(following_header(best))->size = old_sz - sz;
      free_list_remove(best);
      free_list_insert_after(following_header(best), NULL);
      return header_to_data(best);
    }
    // Otherwise, ask the operating system for new heap space.
    // If heap_base is NULL, get the heap's base value first.
    if (!heap_base)
        heap_base = sbrk(0);
    memblock_header* hdr = (memblock_header*) sbrk(sz);
    hdr->free = 0;
    hdr->size = sz;
    header_to_trailer(hdr)->size = sz;
    return header_to_data(hdr);
}

// Coalesce two free chunks, chunk1 and chunk2, to form a single free chunk.
// We assume chunk2 is located in memory immediately after chunk1.
static void coalesce(memblock_header* chunk1, memblock_header* chunk2) {
  assert(chunk1->free && chunk2->free);
  assert(chunk2 == following_header(chunk1));
  // Your code here
}

void myfree(void *ptr) {
    if (ptr) {
        memblock_header* hdr = data_to_header(ptr);
        assert(!hdr->free);
        free_list_insert_after(hdr, NULL);
        // Your code here
    }
}


// Given an allocation header, return the corresponding data pointer.
static void* header_to_data(memblock_header* hdr) {
    return hdr + 1;
}

// Given an allocation (a data pointer), return a pointer to the
// corresponding header.
static memblock_header* data_to_header(void* data) {
    return (memblock_header*) data - 1;
}

// Given an allocation header with correct size, return the corresponding
// allocation trailer.
static memblock_trailer* header_to_trailer(memblock_header* hdr) {
    char* endblock = (char*) hdr + hdr->size;
    return (memblock_trailer*) endblock - 1;
}

// Given an allocation header, return the next allocation header
// in address order. This might be free or not. Returns NULL if
// `hdr` is the last allocation header in the heap.
static memblock_header* following_header(memblock_header* hdr) {
    char* endblock = (char*) hdr + hdr->size;
    if (endblock < (char*) sbrk(0))
        return (memblock_header*) endblock;
    else
        return NULL;
}

// Given an allocation header, return the previous allocation header
// in address order. This might be free or not. Returns NULL if
// `hdr` is the first allocation header in the heap.
static memblock_header* previous_header(memblock_header* hdr) {
    if ((char*) hdr > (char*) heap_base) {
        memblock_trailer* prev_trailer = (memblock_trailer*) hdr - 1;
        return (memblock_header*) ((char*) hdr - prev_trailer->size);
    } else
        return NULL;
}

// Mark `hdr` as free and insert it into the free list after `prev`.
static void free_list_insert_after(memblock_header* hdr,
                                   memblock_header* prev) {
    assert(!hdr->free);
    hdr->free = 1;
    hdr->prev = prev;
    if (prev) {
        hdr->next = prev->next;
        prev->next = hdr;
    } else {
        hdr->next = free_list;
        free_list = hdr;
    }
    if (hdr->next)
        hdr->next->prev = hdr;
}

// Mark `hdr` as allocated and remove it from the free list.
static void free_list_remove(memblock_header* hdr) {
    assert(hdr->free);
    hdr->free = 0;
    if (hdr->prev)
        hdr->prev->next = hdr->next;
    else
        free_list = hdr->next;
    if (hdr->next)
        hdr->next->prev = hdr->prev;
}


// Return the current size of the heap.
size_t mymalloc_heap_size(void) {
    // Your code here
    return 0;
}

// Return the amount of free space in the heap, not counting overhead.
size_t mymalloc_free_space(void) {
    // Your code here
    return 0;
}

// Return the per-allocation overhead for headers and trailers.
size_t mymalloc_allocation_overhead(void) {
    return sizeof(memblock_header) + sizeof(memblock_trailer);
}


// Don't complain about unused helper functions.
static void __attribute__((used)) use_helper_functions(void) {
    (void) following_header;
    (void) previous_header;
    (void) free_list_insert_after;
}
