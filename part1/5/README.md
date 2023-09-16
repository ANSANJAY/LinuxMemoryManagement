User space virtual address space
=================================

	 		 address|-------------------| command-line arguments
   				|-------------------| and environment variables
				|        stack      |
				|-------------------|
				|	            |
				|		    |
				|		    |
				|-------------------|
				|		heap|
				|-------------------|
				|uninitialized data | initialized to
				|		(bss| zero by exec
				|-------------------|
				| initialized data  | read from
				|-------------------| program file 
				|		text| by exec
	low address 		|-------------------|
			Typical memory arrangement

$ cat /proc/pid/maps
