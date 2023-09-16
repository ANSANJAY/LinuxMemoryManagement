Low and High Memory
====================

The Linux kernel has its own virtual address space, as every user mode process does.

The kernel code and data structures must fit into that space, but the biggest consumer of kernel address space is virtual mappings for physical memory.

The kernel to access physical memory should first map it into the kernel's virtual address space. 

Maximum amount of physical memory handled by the kernel = amount that could be mapped into the kernel's portion of virtual address space - Space used by kernel code.

As, a result x86 based Linux systems could work with a maximum of a little under 1 GB of physical memory.

The virtual address space of the kernel (1 GB sized in a 3G/1G split) is divided into two parts:

	-->	Low memory or LOWMEM, which is the first 896 MB
	-->	High memory or HIGHMEM, represented by the top 128 MB

                                           Physical mem 
       Process address space    +------> +------------+ 
                                |        |  3200 M    | 
                                |        |            | 
    4 GB+---------------+ <-----+        |  HIGH MEM  | 
        |     128 MB    |                |            | 
        +---------------+ <---------+    |            | 
        +---------------+ <------+  |    |            |  
        |     896 MB    |        |  +--> +------------+          
    3 GB+---------------+ <--+   +-----> +------------+  
        |               |    |           |   896 MB   | LOW MEM 
        |     /////     |    +---------> +------------+ 
        |               |      
    0 GB +---------------+ 
