Maximum Amount of memory can be allocated using vmalloc
============================================================

The vmalloc upper limit is, in theory, the amount of physical RAM on the system.

Kernel reserves an architecture (cpu) specific “range” of virtual memory for the purpose of vmalloc: from VMALLOC_START to VMALLOC_END.

Header file: <asm/pgtable.h>
