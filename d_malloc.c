#include "d_malloc.h"
#include <unistd.h>

m_block find_free_space(m_block *last, size_t size) {
	m_block current_blk = *last;

	while(current_blk && !(current_blk->free && current_blk->size >= size)) {
		*last = current_blk;
		current_blk = current_blk->next;
	}
	return current_blk;
}

m_block request_space(m_block last, size_t size) {
	m_block blk_ptr = (m_block) sbrk(0);
	void *requested_ptr = sbrk(META_SIZE + size);
	
	if (requested_ptr == (void*) -1) {
		puts("Something went wrong when increasing the program break.");
		return NULL;
	}

	blk_ptr->size = size;
	blk_ptr->free = 0;
	blk_ptr->next = NULL;

	if (last) {
		last->next = blk_ptr;
	}
	return blk_ptr;
}

void *malloc(size_t size) {
	if (size < 0) {
		puts("Incompatible size.");
                return NULL;
	}
	m_block blk_to_return = NULL;

	if (!global_last) {
		blk_to_return = request_space(NULL, size);
		global_last = blk_to_return;
	} else {
		m_block last = global_last;
		m_block found_free_space = find_free_space(&last, size);
		if (found_free_space) {
			found_free_space->free = 1;
		} else {
			blk_to_return = request_space(last, size);
		}
	}
	if (!blk_to_return) {
		return NULL;
	}
	return blk_to_return + 1;
}

int main(int argc, char *argv) {
	return 0;
}
