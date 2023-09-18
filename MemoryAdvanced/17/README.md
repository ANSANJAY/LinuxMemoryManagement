checkstack.pl
=================

There's a way to get a list of how much stack space each function in your program uses

checkstack.pl

It prints out a list of functions and their stack usage, biggest first	

$ objdump -D hello.ko | perl ~/linux-5.2.8/scripts/checkstack.pl

Note: it can't take into account recursive functions. It only performs static analysis
