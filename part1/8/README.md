High Memory
============

The top 128 MB of the kernel address space is called the high memory region. 

It is used by the kernel to temporarily map physical memory above 1 GB

When physical memory above 1GB (or more precisely 896MB) needs to be accessed, the kernel uses those 128MB to create a temporary mapping to its virtual address space, thus achieving the goal of being able to access all physical pages.

The physical memory above 896 MB is mapped on demand to the 128 MB of the HIGHMEM region.

Mapping to access high memory is created on the fly by the kernel, and destroyed when done. This makes high memory access slower. 

Concept of high memory does not exist on 64-bit systems, due to the huge address range (2^64), where the 3G/1G split does not make sense anymore.
