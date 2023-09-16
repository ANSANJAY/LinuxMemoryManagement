Virtual Address Space for 32-bit processors
=============================================

On Linux, every memory address is virtual. They do not point to any address in the RAM directly.

Whenever you access a memory location, a translation mechanism is performed in order to match the corresponding phyical memory.

On Linux Systems, each process owns a virtual address space.

Size of the virtual address space is 4GB on 32-bit systems (even on a system with physical memory less than 4 GB)

Linux divides this virtual address space into 

	--->	an area for applications, called user space

	--->	an area for kernel, called kernel space

The split between the two is set by a kernel configuration parameter named PAGE_OFFSET.

This is called 3G/1G Split.

      .------------------------. 0xFFFFFFFF 
      |                        | (4 GB) 
      |    Kernel addresses    | 
      |                        | 
      |                        | 
      .------------------------.CONFIG_PAGE_OFFSET 
      |                        |(x86: 0xC0000000, ARM: 0x80000000) 
      |                        | 
      |                        | 
      |  User space addresses  | 
      |                        | 
      |                        | 
      |                        | 
      |                        | 
      '------------------------' 00000000


User address space is allocated per process, so that each process runs in a sandbox, separated from others.

The kernel address space is same for all process; there is only one kernel.

Why kernel shares its address space  with every process
=========================================================

	--> Every single process uses system calls, which will involve the kernel

	--> Mapping the kernel's virtual memory address into each process virtual address space allows us to avoid the cost of switching out the memory address space on each entry to and exit from the kernel

64- bit memory map
======================

===========================================================================================
    Start addr    |   Offset   |     End addr     |  Size   | VM area description
===========================================================================================
                  |            |                  |         |
 0000000000000000 |    0       | 00007fffffffffff |  128 TB | user-space virtual memory
__________________|____________|__________________|_________|______________________________
                  |            |                  |         |
 0000800000000000 | +128    TB | ffff7fffffffffff | ~16M TB | non-canonical
__________________|____________|__________________|_________|______________________________
                  |            |                  |         |
 ffff800000000000 | -128    TB | ffffffffffffffff |  128 TB | kernel-space virtual memory
__________________|____________|__________________|_________|______________________________

Documentation/x86/x86_64/mm.txt
