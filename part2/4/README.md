kmalloc may internally round up allocations and return more memory than requested.

ksize() can be used to determine the actual amount of memory allocated.

The caller may use this additional memory, even though  a smaller amount of memory was initially specified with the kmalloc call.

This function is not often needed; callers to kmalloc() usually know what they allocated. It can be useful, though, in situations where a function needs to know the size of an object and does not have that information handy.

