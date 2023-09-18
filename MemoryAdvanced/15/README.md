Kernel Stack
==============

In a Linux System, every process has 2 stacks:
	User stack
	Kernel stack

User Stack in x86: Resides in user address space (0-3GB in 32-bit x86)
Kernel Stack in x86: Resides in kernel address space(3GB-4GB in 32-bit x86)

User space is afforded the luxury of a large, dynamically growing stack, whereas the kernel has no such luxury

The kernel's stack is small and fixed.

Size of the per-process kernel stacks depends on both the architecture and a compile-time option.

When the option is enabled, each process is given only a single page - 4KB on 32-bit architectures and 8KB on 64-bit architectures.

Why only one page?
	1. Less memory consumption per process
	2. As uptime increases, it becomes increasingly hard to find two physically contiguous unallocated pages.


Historically, interrupt handlers also used the kernel stack of the process they interrupted.

As it placed tighter constraints on the already smaller kernel stack. kernel developers implemented a new feature: interrupt stacks. Interrupts use their own stacks. It consumes only a single page per processor.

Now, we have a kernel stack size of 16KB from Linux 3.15 in x86_64
