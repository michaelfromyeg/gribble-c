# Pointers

- Pointers are references to memory, typically on the heap
  - Another way to think about pointers is that they are the type for an address on your machine
  - Pointers are commonly used for strings and structs
  - They allow us to perform operations "in place" through pass-by-reference (instead of copying values, known as pass-by-value)
- Pointers are declared using `*` in the following way

    ```C
    int *c;

    int *c, d; // d is an int, c is an int pointer

    int *c = &d; // "&" on the RHS is like "address of"
    ```

  - Pointers have a fixed size depending on the architecture they're used on; on a 64-bit machine, pointers will be 8-bytes long to cover the entire address space
  - On the right-hand side of an expression, `*` is a pointer de-reference
    - Essentially, this means follow the address and return the value at that address (with a size dependent on the type of thing you're pointing too)
    - On the left-hand side, this notation allows us to assign a pointer's value
- Pointers shift values depending on their size
  - Adding two to a pointer really says, point to the object after the next two; fittingly, this translates to `p = p + i * sizeof(<object>)`
  - Pointers do this under the hood as a kind of nicety to save us some thinking
  - This is actually how array notation works; `arr[2]` is just like `*(arr+2)`
- We can also have pointers to structs
  - To save us from having to write `(*mystruct).field` all the time, the arrow notation exists; we can instead do `mystruct->field`
- Pointers to functions are also a thing!
  - They have rather tricky syntax; they are declared as `<type> (*fn)(<type> arg1, ...)`
  - These allows us to pass functions as parameters to other functions
- To pass-by-reference, remember to pass the address of the value you'd like to modify
- There are a number of memory-related helper functions included in `<stdlib.h>`
  - In particular, `malloc()` gives a number of bytes
  - `calloc()` takes the number of elements and the size of each element; it also initializes the values to 0
  - `realloc()` allows you to adjust an initial pointer size (e.g., the extend an array)
  - `free()` marks a memory block as unused
  - TODO: check out `memcpy()`!
