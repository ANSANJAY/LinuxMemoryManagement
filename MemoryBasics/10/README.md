kmalloc family allocation
============================

kmalloc is a kernel memory allocation function, such as malloc() in user space

Memory returned by kmalloc is contiguous in physical memory and in virtual memory:


			virtual memory    physical memory
			----------        --------
		   - - -|	 |------- |	 |
	kmalloc	  /	|	 |        |	 |
	---------/	|        |        |	 |
	|	|	|        |        |	 |
	|	|   ---	|        |------- | 	 |
	|	|  /	|        |	  |	 |
	|	| /	|        |	  |	 |
	---------/	|        |	  |	 |
			|        |	  |	 | 
			|        |        |      |
			|        |        |      |
			|        |        |      |
			|        |        |      |
			----------        --------


kmalloc allocator is the general and higher-level memory allocator in the kernel, and relies on SLAB Allocator

Memory returned from kmalloc has a kernel logical address because it is allocated from the LOW_MEM region, unless HIGH_MEM is specified.

Header File: #include <linux/slab.h>

void *kmalloc(size_t size, int flags); 

	size: specifies the size of the memory to be allocated (in bytes).
	flags: determines how and where memory should be allocated. 
		Available flags are the same as the page allocator (GFP_KERNEL, GFP_ATOMIC, GFP_DMA, and so on)


Return Value: On Success, returns the virtual address of the chunk allocated, which is guaranteed to be physically contiguous.  On error, it returns NULL

Flags
=============

GFP_KERNEL: This is the standard flag. We cannot use this flag in the interrupt handler because its code may sleep. It always returns memory from the LOM_MEM zone (hence a logical address).

GFP_ATOMIC: This guarantees the atomicity of the allocation. The only flag to use when we are in the interrupt context.

GFP_USER: This allocates memory to a user space process. Memory is then distinct and separated from that allocated to the kernel.

GFP_HIGHUSER: This allocates memory from the HIGH_MEMORY zone.

GFP_DMA: This allocates memory from DMA_ZONE.

kfree
==========

The kfree function is used to free the memory allocated by kmalloc. The following is the prototype of kfree():

void kfree(const void *ptr) 

Memory corruption can happen:
	
	--->	on a block of memory that already has been freed

	--->	on a pointer that is not an address returned from kmalloc()

Always balance allocations and frees to ensure that kfree() is called exactly once on the correct pointer

