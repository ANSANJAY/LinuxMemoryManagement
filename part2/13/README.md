kmalloc(0) returns a special ZERO_SIZE_PTR value. 
It is a non-NULL value which looks like a legitimate pointer, but which causes a fault on any attempt at dereferencing it.
 Any attempt to call kfree() with this special value will do the right thing, of course.
