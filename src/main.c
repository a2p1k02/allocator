#include <stdio.h>
#include <assert.h>
#include "allocator/allocator.h"

int main()
{
    word_t* p1 = allocate(3);
    Block* p1b = get_header(p1);

    assert(p1b->size == sizeof(word_t));

    word_t* p2 = allocate(8);
    Block* p2b = get_header(p2);

    assert(p2b->size == 8);

    fprintf(stderr, "\nAll assertions passed!\n");

    return 0;
}
