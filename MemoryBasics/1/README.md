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

5.  **who decides the structure ?**
vendor ,refer datasheet



```bash
[anamika@Ana ~]$ sudo cat /proc/iomem 
00000000-00000fff : Reserved
00001000-0009efff : System RAM
0009f000-000fffff : Reserved
  000a0000-000bffff : PCI Bus 0000:00
  000f0000-000fffff : System ROM
00100000-5bc31fff : System RAM
5bc32000-5bcbafff : Reserved
5bcbb000-60729fff : System RAM
6072a000-64510fff : Reserved
64511000-64d71fff : ACPI Non-volatile Storage
  64d03000-64d03fff : USBC000:00
64d72000-64ffefff : ACPI Tables
64fff000-64ffffff : System RAM
65000000-68ffffff : Reserved
69400000-695fffff : Reserved
69e00000-707fffff : Reserved
  6c800000-707fffff : Graphics Stolen Memory
70800000-bfffffff : PCI Bus 0000:00
  70800000-70800fff : 0000:00:1f.5
  74000000-8a0fffff : PCI Bus 0000:01
  8c000000-8dffffff : 0000:00:0e.0
    8c000000-8dffffff : VMD MEMBAR1
      8c000000-8c0fffff : PCI Bus 10000:e1
        8c000000-8c003fff : 10000:e1:00.0
          8c000000-8c003fff : nvme
c0000000-ce0fffff : PCI MMCONFIG 0000 [bus 00-e0]
fd000000-fd68ffff : pnp 00:06
fd690000-fd69ffff : INT34C5:00
  fd690000-fd69ffff : INT34C5:00 INT34C5:00
fd6a0000-fd6affff : INT34C5:00
  fd6a0000-fd6affff : INT34C5:00 INT34C5:00
fd6b0000-fd6cffff : pnp 00:06
fd6d0000-fd6dffff : INT34C5:00
  fd6d0000-fd6dffff : INT34C5:00 INT34C5:00
fd6e0000-fd6effff : INT34C5:00
  fd6e0000-fd6effff : INT34C5:00 INT34C5:00
fd6f0000-fdffffff : pnp 00:06
fe000000-fe01ffff : pnp 00:06
fe04c000-fe04ffff : pnp 00:06
fe050000-fe0affff : pnp 00:06
fe0d0000-fe0fffff : pnp 00:06
fe200000-fe7fffff : pnp 00:06
fec00000-fec003ff : IOAPIC 0
fed00000-fed003ff : HPET 0
  fed00000-fed003ff : PNP0103:00
fed20000-fed7ffff : Reserved
  fed40000-fed44fff : INTC6000:00
    fed40000-fed44fff : INTC6000:00
fed84000-fed84fff : dmar1
fed90000-fed90fff : dmar0
fed91000-fed91fff : dmar2
feda0000-feda0fff : pnp 00:05
feda1000-feda1fff : pnp 00:05
fedc0000-fedc7fff : pnp 00:05
fee00000-feefffff : pnp 00:05
  fee00000-fee00fff : Local APIC
ff000000-ffffffff : pnp 00:06
100000000-28f7fffff : System RAM
  198000000-1991fffff : Kernel code
  199200000-199fb1fff : Kernel rodata
  19a000000-19a325b7f : Kernel data
  19acd5000-19bdfffff : Kernel bss
28f800000-28fffffff : RAM buffer
4000000000-7fffffffff : PCI Bus 0000:00
  4000000000-400fffffff : 0000:00:02.0
  4010000000-4016ffffff : 0000:00:02.0
  4017000000-4017000fff : 0000:00:15.0
    4017000000-40170001ff : lpss_dev
      4017000000-40170001ff : i2c_designware.0 lpss_dev
    4017000200-40170002ff : lpss_priv
    4017000800-4017000fff : idma64.0
      4017000800-4017000fff : idma64.0 idma64.0
  4017001000-4017001fff : 0000:00:15.1
    4017001000-40170011ff : lpss_dev
      4017001000-40170011ff : i2c_designware.1 lpss_dev
    4017001200-40170012ff : lpss_priv
    4017001800-4017001fff : idma64.1
      4017001800-4017001fff : idma64.1 idma64.1
  4020000000-40ffffffff : 0000:00:02.0
  6000000000-6021ffffff : PCI Bus 0000:01
  6022000000-6023ffffff : 0000:00:0e.0
  6024000000-6024ffffff : 0000:00:02.0
  6025000000-60250fffff : 0000:00:1f.3
    6025000000-60250fffff : Audio DSP
  6025100000-60251fffff : 0000:00:0e.0
    6025102000-60251fffff : VMD MEMBAR2
  6025200000-602523ffff : 0000:00:0d.2
    6025200000-602523ffff : thunderbolt
  6025240000-602525ffff : 0000:00:04.0
    6025240000-602525ffff : proc_thermal
  6025260000-602526ffff : 0000:00:14.0
    6025260000-602526ffff : xhci-hcd
  6025270000-602527ffff : 0000:00:12.0
    6025270000-602527ffff : intel_ish_ipc
  6025280000-602528ffff : 0000:00:0d.0
    6025280000-602528ffff : xhci-hcd
  6025290000-6025297fff : 0000:00:0a.0
    6025294000-60252948ff : telem0
    6025296198-60252961a7 : intel_vsec.telemetry.0
    60252961a8-60252961b7 : intel_vsec.telemetry.0
  6025298000-602529bfff : 0000:00:1f.3
    6025298000-602529bfff : Audio DSP
  602529c000-602529ffff : 0000:00:14.3
    602529c000-602529ffff : iwlwifi
  60252a0000-60252a3fff : 0000:00:14.2
  60252a4000-60252a40ff : 0000:00:1f.4
  60252a5000-60252a5fff : 0000:00:16.0
    60252a5000-60252a5fff : mei_me
  60252a8000-60252a8fff : 0000:00:14.2
  60252a9000-60252a9fff : 0000:00:0d.2

```