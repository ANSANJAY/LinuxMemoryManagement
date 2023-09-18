Memory allocation mechanism
==============================

	----------------------------------
	|	Kernel			 |
	|	Module			 |
	----------------------------------
	    |		|	|	|
	    v	        |	|	v
	----------	|	|  -----------
	|         |	|	|  |         |
	|kmalloc  |	|	|  |vmalloc  |
	|allocator|	|	|  |allocator|
	----------	|	|  -----------
	   |            |	|
	   v	        v	|
	-----------------	|	
	| slab       	|	|
	| allocator  	|	|
	----------------	|
		|		|
		v		v
	------------------------------------------
	|	Page Allocator			 |
	|Allocate physical memory by chunk of 4k |
	------------------------------------------
			|
			|	
			v
	---------------------------------------
	|	Main Memory		      |
	|				      |
	---------------------------------------

There is an allocation mechanism to satisfy any kind of memory request.

Depending on what you need memory for, you can choose the one closest to your goal.

The main allocator is the page allocator, which only works with pages (a page being the smallest memory unit it can deliver)

Then comes the SLAB allocator which is built on top of the page allocator, getting pages from it and returning smaller memory entities (by mean of slabs and caches). This is the allocator on which the kmalloc allocator relies.
