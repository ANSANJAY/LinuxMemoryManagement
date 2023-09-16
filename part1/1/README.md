## Detailed Notes for Revision 📝

### Physical Address Space 🌌

The **Physical Address Space** refers to the entire span of memory addresses that can be accessed by a processor. In simpler terms, it's the "real" memory of your computer.

#### Key Insights 🔑

- 32-bit systems have an address space of \(2^{32}\), which equals **4 GB**.
- This space isn't just for your RAM. It also encompasses:
  - **RAM** 🖥️
  - **BIOS** 💾
  - **APIC** 🔄
  - **PCI** 🌉
  - **Other Memory Mapped I/O Devices** 🔌

#### Memory Layout Visualization 🖼️

```plaintext
+------------------+  <- 0xFFFFFFFF (4GB) Top of addressable space
|      32-bit      |
|  memory mapped   |
|     devices      |
|                  |
/\/\/\/\/\/\/\/\/\/\

/\/\/\/\/\/\/\/\/\/\
|                  |
|      Unused      |
|                  |
+------------------+  <- Depends on the amount of RAM
|                  |
|                  |
| Extended Memory  |
|                  |
|                  |
+------------------+  <- 0x00100000 (1MB)
|     BIOS ROM     |
+------------------+  <- 0x000F0000 (960KB)
|  16-bit devices, |
|  expansion ROMs  |
+------------------+  <- 0x000C0000 (768KB)
|   VGA Display    |
+------------------+  <- 0x000A0000 (640KB)
|                  |
|    Low Memory    |
|                  |
+------------------+  <- 0x00000000 Base of addressable space
```

#### Pro Tip 💡

You can view the current map of the system's memory for each physical device using:

```bash
$ cat /proc/iomem 
```

### Questions & Answers 🤔💡

1. **What does the Physical Address Space represent in computing?**
   
   📜 **Answer:** 
   The Physical Address Space denotes the entire range of memory addresses that a processor can access. It's the actual memory addresses of a computer system.

2. **How much address space can a 32-bit system access, and why?**
   
   📜 **Answer:** 
   A 32-bit system can access \(2^{32}\) addresses, amounting to 4 GB. This is due to the number of unique addresses a 32-bit system can represent.

3. **Name at least three components or devices that use the Physical Address Space.**
   
   📜 **Answer:** 
   The Physical Address Space is used by multiple components, including RAM, BIOS, and PCI.

4. **What is the significance of the `/proc/iomem` file?**
   
   📜 **Answer:** 
   The `/proc/iomem` file provides a map of the current system's memory, showcasing how the physical address space is allocated for each device.

Remember, the key to acing questions on this topic is understanding the concept of physical address space deeply and being able to explain it clearly and concisely. Happy revising! 📘🚀
