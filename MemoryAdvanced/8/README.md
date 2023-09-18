vmalloc
============================

Memory returned by vmalloc is only contiguous in virtual memory and not in physical memory

			virtual memory    physical memory
			----------        --------
		   - - -|	 |--------|	 |
	vmalloc	  /	|	 |        |	 |
	---------/	|        |--------|	 |
	|	|	|        |\       |	 |
	|	|   ---	|        | \	  | 	 |
	|	|  /	|        |\ ----- |	 |
	|	| /	|        | \	  |	 |
	---------/	|        |  ------|	 |
			|        |	  |	 | 
			|        |        |      |
			|        |        |      |
			|        |        |      |
			|        |        |      |
			----------        --------

The returned memory always comes from HIGH_MEM zone. 
