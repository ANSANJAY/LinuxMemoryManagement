Kinds of Memory
===============

Kernel and user space work with virtual addresses .

These virtual addresses are mapped to physical addresses by memory management hardware (MMU)

Header File: #include <asm/io.h>

phys_addr = virt_to_phys(virt_addr);
virt_addr = phys_to_virt(phys_addr);
