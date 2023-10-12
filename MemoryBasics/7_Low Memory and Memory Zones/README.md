# Low Memory and Memory Zones in Linux 📚💻

### Low Memory Overview 📉🔍

**Low Memory** is the portion of the kernel's virtual address space that is permanently and directly mapped to the first **896 MB** of physical memory on x86 architectures with a **32-bit address space**. 
- Because of its **permanent mapping**, the translation between virtual addresses (logical addresses) in this region and their corresponding physical addresses is straightforward.

### Logical Addresses 🖥️➡️📦

The term **logical address** in this context refers to virtual addresses within the low memory.
-  These addresses can be easily converted to their corresponding physical addresses.
-  The permanent nature of the mapping means that there's a **fixed offset between the virtual and physical addresses.**

**Converting Addresses**:
- `__pa(address)`: Translates a logical address to its physical counterpart.
- `__va(address)`: Converts a physical address to its logical counterpart.

### Memory Zones ⚡🔲

To manage memory efficiently, the Linux kernel divides it into **zones**. These zones reflect the different capabilities and purposes of memory areas:

1. **ZONE_DMA**:
   - This is the range of memory that can be used for Direct Memory Access (DMA) by devices that cannot address the entire range of physical memory. 
   - Historically, certain devices could only do DMA into the first **16 MB of RAM**. 
   - Thus, this zone captures the **page frames below 16 MB**

2. **ZONE_NORMAL**:
   - This is the regular addressable range of memory used for most normal system operations.
   - It spans the range from just **above 16 MB up to (and not including) the 896 MB** boundary in our 3G/1G split example.

3. **ZONE_HIGHMEM**:
   - Contains page frames from the rest of physical memory, from 896 MB onwards.
   - This memory isn't permanently mapped into the kernel's address space and thus accessing it requires on-the-fly mappings, a slightly more complex process.
   
### How Memory Zones are Allocated 🔄💾

Using the example of a system with **512 MB of RAM**:
- **ZONE_DMA**: Would have the first 16 MB, since DMA-capable devices need this chunk.
- **ZONE_NORMAL**: Would have the remaining memory from 16 MB up to 512 MB (496 MB in total). 
- **ZONE_HIGHMEM**: On a 512 MB system, there is **no memory above the 896 MB threshold**, so this zone doesn't exist.

These zones help the kernel manage memory in a way that accommodates both the requirements of the hardware and the operational needs of the system. The proper separation and allocation of these zones ensure the smooth functioning of various kernel and hardware operations.


