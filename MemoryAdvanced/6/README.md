krealloc
==========

Memory allocated by kmalloc() can be resized by:

void *krealloc(const void *p, size_t new_size, gfp_t flags);

