Pages
===========

Virtual address space (0x00000000 to 0xffffffff) is divided into pages of 4096 bytes.

The page size may differ in other systems. But on ARM and x86 it is fixed.

The size of a page is defined in the kernel through the PAGE_SIZE macro.

Pages in the virtual address space are mapped to physical addresses by the Memory Management Unit(MMU), which uses page tables to perform the mapping.

Memory Page/Virtual Page/Page: 
	Refers to a fixed length contiguous block of virtual memory. 
	Kernel data structure to represent a memory page is struct page

Frame/Page Frame:
	Refers to a fixed length contiguous block of physical memory on top of which the OS maps a memory page
	Each page frame is given a page frame number (PFN).
	Given a page, you can easily get its PFN and vice versa, using page_to_pfn/pfn_to_page macros

Page Table:
	Kernel and architecture data structure used to store the mapping between virtual addresses and physical addresses
	Each entry describes key pair page/frame


Command to find out page size
===============================

$ getconf PAGESIZE
or
$ getconf PAGE_SIZE



				
