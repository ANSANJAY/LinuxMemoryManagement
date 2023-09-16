## Detailed Notes on Low and High Memory 📚💼

### Kernel's Address Space 🖥️📍

Linux kernel operates in its own virtual address space distinct from user mode processes. This separation ensures both security and stability, as user processes can't directly access kernel structures or data.

### Kernel's Virtual Address Mappings 🗺️📌

For the kernel to operate on physical memory (e.g., for caching, memory allocation, etc.), it must first map this physical memory into its own virtual address space. This mapping ensures that every physical byte of RAM has a corresponding virtual address in the kernel's address space.

### Limitations on x86 🚫🔍

On x86 architectures with a 32-bit address space and a 3G/1G split:

- The kernel's virtual address space is restricted to 1 GB.
  
- Of this, only a portion can be used for mapping physical memory, as some of the address space is used by the kernel code itself and its data structures.

- Because of this, the Linux kernel on these systems can only natively handle slightly less than 1 GB of physical memory.

```lua
       +-----------------------------------+
       |            Physical mem           |
       |       +----------------------+     |
       |       |                      |     |
       |       |        3200 M        |     |
       |       |                      |     |
       |       |      HIGH MEM        |     |
       |       +----------------------+     |
       |                                   |
       |       +----------------------+     |
       |       |                      |     |
       |       |       896 MB         |     |
       |       |                      |     |
       |       |      LOW MEM         |     |
       |       +----------------------+     |
       +-----------------------------------+
       
       +-----------------------------------+
       |       Process address space       |
       |                                   |
       |                                   |
       |      4 GB                        |
       |       +----------------------+     |
       |       |                      |     |
       |       |       128 MB         |     |
       |       +----------------------+     |
       |                                   |
       |       +----------------------+     |
       |       |                      |     |
       |       |       896 MB         |     |
       |       +----------------------+     |
       |                                   |
       |      3 GB                        |
       |       +----------------------+     |
       |       |                      |     |
       |       |       /////          |     |
       |       +----------------------+     |
       |      0 GB                        |
       +-----------------------------------+
```

### Dividing the Kernel's Address Space: LOWMEM and HIGHMEM 🌍🌌

- **LOWMEM (Low Memory)**:
  - Refers to the first 896 MB of the kernel's virtual address space.
  - Memory in LOWMEM is permanently mapped into the kernel's address space, meaning its virtual addresses are always valid.
  - Kernel operations mostly occur in this region because it's quickly accessible.
  
- **HIGHMEM (High Memory)**:
  - The remaining portion, roughly the top 128 MB.
  - Physical pages mapped into HIGHMEM are not permanently mapped into the kernel's address space. Instead, they are temporarily mapped when needed.
  - HIGHMEM exists because of the need to support systems with more than the naturally addressable amount of memory (more than the ~1 GB limitation).
  - Operations on HIGHMEM are slightly more costly in terms of time because of the need to set up temporary mappings.

### Why the Distinction? 🤔📈

The distinction between LOWMEM and HIGHMEM emerged as a solution to a problem: As systems started to ship with more than 1 GB of RAM, how could a 32-bit kernel efficiently address it all? 

LOWMEM is always mapped, making it the fastest memory for the kernel to access. HIGHMEM, however, involves overhead due to the on-the-fly mappings but allows 32-bit systems to use more physical memory than they can permanently map in their address space.

### Questions & Answers 🤔💡

1. **Why don't we just use all memory as LOWMEM?**

   📜 **Answer:** Due to the limited address space in a 32-bit system (specifically, the 1 GB allocated to the kernel), we can't map all of a large physical memory space into LOWMEM. Doing so would mean we'd run out of space for other kernel structures and code. The introduction of HIGHMEM allows us to extend beyond this limitation.

2. **Is HIGHMEM relevant on 64-bit systems?**

   📜 **Answer:** No, 64-bit systems have a vastly larger address space. This means they can address a much larger amount of physical memory without resorting to mechanisms like HIGHMEM. HIGHMEM is a workaround specifically tailored for 32-bit systems with more than ~1 GB of RAM.

Always keep in mind that the architecture of a system, including how its memory is managed, impacts the performance, flexibility, and scalability of the system. Happy learning! 🌟📘
