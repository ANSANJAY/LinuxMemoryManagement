The kmalloc() function returns physically and virtually contiguous memory.

Physically contiguous memory has two primary benefits.
        1.  many hardware devices cannot address virtual memory.
        2.      a physically contiguous block of memory can use a single large page mapping. This minimizes the translation lookaside buffer (TLB) overhead of addressing the memory

Allocating physically contiguous memory has one downside: it is often hard to find physically contiguous blocks of memory, especially for large allocations

