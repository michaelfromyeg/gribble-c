# Strings

- Arrays are really just a string of characters in C
  - Constant character strings are written in double-quotes
  - Single characters are declared using single-quotes
  - Strings are null terminated; the last element of a character array is the null character, written `\0`
  - You can kind-of shorten strings by inserting a null character, but you cannot lengthen strings by assigning a new constant to the variable
- To manipulate strings in C, use `<string.h>`'s many helpers
- To convert numbers to string, use `sprintf` instead of `printf`; you'll need a pre-set buffer
- We can create arrays of strings; it's really an array of character pointers, each of variable size
