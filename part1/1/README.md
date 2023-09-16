What is physical address space?
===================================

The entire range of memory addresses accessible by processors is often referred to as physical address space

32 Bit systems can have address space of 2^32 = 4 GB

This Physical address space is used by

	--->	RAM

	--->	BIOS

	--->	APIC

	--->	PCI

	--->	Other Memory Mapped I/O Devices


+------------------+  <- 0xFFFFFFFF (4GB)
|      32-bit      |
|  memory mapped   |
|     devices      |
|                  |
/\/\/\/\/\/\/\/\/\/\

/\/\/\/\/\/\/\/\/\/\
|                  |
|      Unused      |
|                  |
+------------------+  <- depends on amount of RAM
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
+------------------+  <- 0x00000000


$ cat /proc/iomem 

This file shows you the current map of the system's memory for each physical device.

