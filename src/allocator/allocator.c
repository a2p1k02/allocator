#include "allocator.h"
#include <stddef.h>

size_t align(size_t n)
{
	return (n + sizeof(word_t) - 1) & ~(sizeof(word_t) - 1);
}

size_t allocate_size(size_t size)
{
	return size + sizeof(Block) - sizeof(((struct Block*)0)->data);
}

Block* request_from_os(size_t size)
{
	Block* block = (Block* ) sbrk(0);
	if (sbrk(allocate_size(size)) == (void *) - 1)
		return NULL;
	return block;
}

word_t* allocate(size_t size)
{
	size = align(size);

	Block* block = request_from_os(size);

	block->size = size;
	block->used = true;
	if (heap == NULL)
		heap = block;

	if (top != NULL)
		top->next = block;

	top = block;

	return block->data;
}

Block* get_header(word_t* data)
{
	return (Block *) ((char *) data + sizeof(((struct Block*)0)->data) - sizeof(Block));
}

void free_memory(word_t* data)
{
	Block* block = get_header(data);
	block->used = false;
}

