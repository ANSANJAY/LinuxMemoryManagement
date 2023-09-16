Low Mem
============

The first 896 MB of kernel address space constitutes the low memory region.

Early in the boot, the kernel permanently maps this 896MB

Addresses that result from this mapping are called logical addresses. 

These are virtual addresses, but can be translated into physical addresses by subtracting a fixed offset, since the mapping is permanent and known in advance.

You can convert a physical address into a logical address using the __pa(address) macro, and then revert it with the __va(address) macro.

Low memory matches with the lower bound of physical addresses.

In fact, to serve different purposes, kernel memory is divided into a zone.

We can then identify three different memory zones in the kernel space:

	ZONE_DMA: This contains page frames of memory below 16 MB, reserved for Direct Memory Access (DMA)
	ZONE_NORMAL: This contains page frames of memory above 16 MB and below 896 MB, for normal use
	ZONE_HIGHMEM: This contains page frames of memory at and above 896 MB

On a 512 MB system, there will be no ZONE_HIGHMEM, 16 MB for ZONE_DMA, and 496 MB for ZONE_NORMAL.


