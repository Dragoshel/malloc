#ifndef D_MALLOC_H
#define D_MALLOC_H

#include <stdio.h>

typedef struct meta_block * m_block;

#define META_SIZE sizeof(struct meta_block)

m_block global_last = NULL;

struct meta_block {
	size_t size;
	int free;
	m_block next;
};

m_block find_free_space(m_block *last, size_t size);

m_block request_space(m_block last, size_t size);

void *malloc(size_t size);

#endif
