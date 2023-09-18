CONFIG_FRAME_WARN
==================

This kernel configuration option passes an option to the compiler to cause it to emit a warning when a static stack size for a routine is detected that is larger than the specified threshold.

It requires gcc version 4.4 or later in order to work

The gcc option used is "-Wframe-larger-than=xxx".

By default, CONFIG_FRAME_WARN has the value of 1024, but you can set it to any value from 0 to 8192.

Linux kernel defines stack size 8192 bytes for each process. the sum of the stack frames of all active functions.
should not overflow 8192 bytes.

This warning does not guarantee that you will overflow the stack space; it just shows that this function makes an overflow more likely (when used together with other big-frame functions, or with many smaller functions).
