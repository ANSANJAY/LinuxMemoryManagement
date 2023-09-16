Kernel memory is managed in a fairly straightforward way. 

It is not demand-paged, meaning that, for every allocation using kmalloc() or similar function, there is real physical memory.

Kernel memory is never discarded or paged out.

Linux employs a lazy allocation strategy for user space, only mapping physical pages of memory when the program accesses it.

For example, allocating a buffer of 1 MiB using malloc(3) returns a pointer to a block of memory addresses but no actual physical memory. 

 A flag is set in the page table entries such that any read or write access is trapped by the kernel. This is known as a page fault.

Only at this point does the kernel attempt to find a page of physical memory and add it to the page table mapping for the process.
