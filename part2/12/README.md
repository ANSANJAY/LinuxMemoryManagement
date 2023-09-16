Differences between vmalloc and kmalloc
========================================

1. Physical Memory:
	kmalloc: Guarantees the pages are physically contiguous and virtually contiguous
	vmalloc: It allocates virtually contiguous but not necessarily physically contiguous

2. Low Mem vs High Mem:
	kmalloc: Returns from Low Memory
	vmalloc: Returns from High Memory	

3. Usage:
	kmalloc: Memory returned Can  be used by hardware devices(DMA, PCI)
	vmalloc: Memory returned Cannot be used by hardware devices

4. Interrupt Context:
	kmalloc: can be used in interrupt context with 'GFP_ATOMIC'
	vmalloc: cannot be used in interrupt context

5. Allocator:
	kmalloc: Uses slab allocator which in turn use Page Allocator
	vmalloc: Directly uses Page Allocator

6. Overhead:
	kmalloc: less overhead
	vmalloc: more overhead, as each vmalloc requires page table changes and a translation look aside buffer invalidation.

7. Size:
	kmalloc: Cannot give large memory
	vmalloc: Useful for allocating large memory and no requirement of physical contiguous
