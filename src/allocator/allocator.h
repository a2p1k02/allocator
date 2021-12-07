#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

typedef intptr_t word_t;

typedef enum {
    false = 0,
    true = 1
} bool;

typedef struct Block {
    size_t size;
    bool used;
    struct Block* next;
    word_t data[1];
} Block;

static Block* heap = NULL;
static Block* top = NULL;

word_t* allocate(size_t size);
size_t align(size_t n);
size_t allocate_size(size_t size);
Block* request_from_os(size_t size);
Block* get_header(word_t* data);
void free_memory(word_t* data);

#endif //ALLOCATOR_H
