#ifndef D_MALLOC_H
#define D_MALLOC_H

#include <stdio.h>

struct meta_block {
	size_t mem_size;
	struct meta_block *next;
	int free;
	int magic;
};

#define META_SIZE sizeof(meta_block)

struct meta_block *find_free_block(size_t size);

struct meta_block *request_space(struct meta_block *last, size_t size);

void *malloc(size_t size);

#endif
