# Memory: Stack vs. Heap

- The stack is a region in the computer's memory for temporary variables
  - It's LIFO (last-in-first-out), meaning the most recently added data is removed first
  - Local variables are allocated and de-allocated as a part of a stack frame, so they exist as long as a function exists
  - Related to "variable scope," so we say local variables are scoped to their function
  - The stack size has an upper limit, too
- The heap is not automatically managed, and is largely free-floating (but also larger)
  - We use `malloc()` or `calloc()` to get a pointer to new memory that's reserved for us
  - `free()` marks that memory as no longer in use
  - Forgetting to free memory results in a "memory leak"; `valgrind` is a command-line tool to detect leaks
  - Commonly, we use pointers to manage and access heap data
  - Variables can be resized using `realloc()`
- The `static` keyword allows a local variable to persist past a function call
  - It's a like a "protected" global variable
- The heap should be used for big data that's used for a long time
- The stack should be used for small amounts of data that are only needed for a short period of time
