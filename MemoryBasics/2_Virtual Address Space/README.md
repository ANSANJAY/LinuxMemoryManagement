# Virtual Address Space for 32-bit Processors 🌌💻

Virtual address space is the `memory address system used by a program`, and 
  - it is mapped to the `physical address space` by the operating system and hardware.

#### Key Insights 🔑

- In **Linux**, every memory address is virtual, meaning it doesn't correspond directly to a physical location in RAM.
- Every time a memory location is accessed, there's a translation mechanism that matches it to the right physical memory.
- On Linux, each process has its own **virtual address space**.
- The size of the virtual address space for 32-bit systems is **4GB**.
  - This remains true even if the physical memory of the system is less than 4 GB.
  ---

- This virtual address space is divided into:
  - **User Space**: Where applications run.
  - **Kernel Space**: Where the operating system kernel operates.
  ---

- The split is determined by a kernel configuration parameter called **PAGE_OFFSET**.
---

  - This configuration is commonly referred to as the **3G/1G Split**.

# Memory split for a 32 bit system 🖼️

```plaintext
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
```


----


```lua
                                  Kernel Virtual Address Space
    +------------------------------------------------------------------------+
    |                                                                        |
    |                                                                        |
    |                                                                        |
    |                          HIGH Memory (HIGHMEM)                         |
    |                  Mapped as needed, up to physical limit                |
    |                  In 32 bit (1GB) case, this is 128 MB                  |
    |                                                                        |
    |                                                                        |
    +------------------------------------------------------------------------+
    |                                                                        |
    |                                                                        |
    |                                                                        |
    |                           Low Memory (LOWMEM)                          |
    |   Direct and permanent mapping of the first part of physical memory    |
    |                        Typically up to 896 MB                          |
    |                                                                        |
    |                                                                        |
    |                                                                        |
    +------------------------------------------------------------------------+
    0 GB                                                                 1 GB

                                          ||
                                          ||
                                          ||
                                          \/
                                  
                                  Physical Memory Space
    +------------------------------------------------------------------------+
    |                                                                        |
    |                                                                        |
    |                                                                        |
    |                         Unused or Additional RAM                       |
    |            (If RAM exceeds the directly mapped `LOWMEM`)               |
    |                                                                        |
    |                                                                        |
    |                                                                        |
    +------------------------------------------------------------------------+
    |                                                                        |
    |                                                                        |
    |                                                                        |
    |                           Low Memory (Direct)                          |
    |              Directly and permanently mapped to virtual space          |
    |                        Typically up to 896 MB                          |
    |                                                                        |
    |                                                                        |
    |                                                                        |
    +------------------------------------------------------------------------+
    0 MB                                                                 1024 MB (1 GB) (Or more, depending on system's total RAM)



```
## NOTE

- **User Address Space**: Unique for each process. Each process operates in its sandbox, isolated from others.
- **Kernel Address Space**: Consistent for all processes, as there's only one kernel.
---

## Why Share Kernel Address Space? 🤔

- Each process frequently employs **system calls** which necessitate the kernel.
- Mapping the kernel's virtual memory into each process's address space avoids the cost and time of constantly switching memory spaces when entering and exiting the kernel.

---


### Virtual Address Space in 64-bit Systems 🌌🖥️

In 64-bit systems, the memory map is vastly expanded, reflecting the larger addressable space of these systems.

#### Visualization 🖼️

```plaintext
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
```
This map can be further understood through the Documentation/x86/x86_64/mm.txt file in the Linux source code.

  - The `mm.txt` file will give you an overview of the virtual memory layout on x86_64 Linux systems, explaining the different regions of the address space and what they are used for (such as user space, kernel space, etc.).

  - Do note that this provides a generic memory layout used by the kernel and not a map of the actual memory usage of your running system.



### Questions & Answers 🤔💡

1. **How does a 32-bit Linux system manage memory addresses?**
   
   📜 **Answer:** 
   In a 32-bit Linux system, every memory address is virtual. There's a translation mechanism to match each virtual address to its corresponding physical memory.

2. **What is the difference between user space and kernel space?**
   
   📜 **Answer:** 
   User space is allocated for applications to run, while kernel space is reserved for the operating system kernel. The kernel space is consistent across all processes, whereas each process has its own distinct user space.

3. **Why is the kernel's virtual memory mapped into each process's virtual address space?**
   
   📜 **Answer:** 
   This setup is beneficial as 
     - every process frequently uses `system calls involving the kernel`.
     -  Having the `kernel's virtual memory mapped to each process's address space` prevents the time-consuming task of constantly switching memory spaces when accessing the kernel.

4. **How does the virtual address space differ between 32-bit and 64-bit systems?**
   
   📜 **Answer:** 
   32-bit systems have a virtual address space of 4GB, divided into user and kernel spaces. 
   - 64-bit systems, on the other hand, have a much larger addressable space, typically divided into user-space virtual memory, non-canonical memory, and kernel-space virtual memory.

 📘🌟

### Simplified Explanation 🌟

Imagine you have a big, giant bookshelf 📚 (this is your computer's memory). Each shelf has different books 📘 (your computer's processes or programs). Now, this bookshelf is so big that you need a map 🗺️ to know where each book is placed. This map is what we call the **Virtual Address Space**.

Now, there are two main sections in this bookshelf. One section is for you, the user 🙋‍♂️, where you keep your favorite books and novels. This section is called the **User Space**. The other section is only for the librarian 🧑‍🏫 (the operating system), and it’s where all the books needed to run the library are kept. This section is called the **Kernel Space**.

On a **32-bit system**, imagine this bookshelf is 4 shelves tall. 📚 Even if we don't have enough books to fill all four shelves, we still map out space for them on our map 🗺️. But in a **64-bit system**, the bookshelf is gigantic, like a skyscraper of bookshelves, allowing us to store way, way more books.

🌟 Keep this analogy in mind, and you'll be able to easily recall the concept during discussions. 👍Sometimes, you need to ask the librarian 🧑‍🏫 for help or to find a book for you. This is like when your programs make **system calls** to the operating system. To make this easier, the librarian’s books (kernel space) are also mapped out on your map 🗺️, so you know where to find the librarian quickly, without needing to swap maps.

Remember, this map 🗺️ (Virtual Address Space) is not the actual bookshelf (Physical Memory); it’s just a way to know where everything is placed on the bookshelf. Each time you, or the librarian, need a book 📘, this map helps in finding the exact shelf and spot of that book in the huge bookshelf. 📚

And that's how the Virtual Address Space works in simple terms! 