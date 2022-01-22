# 5. Functions

- Create sub-routines to abstract away portions of a program
- Functions have a return type, arguments (with types), and contained logic
  - A function may return `void` if it returns nothing at all
  - Recursion and memoization are possible in C
  - Variables are scoped within the function
    - Local variables may persist if they're declared as `static`; it's like a "global variable that can only be accessed within the function in which it's declared"
  - Variadic functions are functions which take a variable number of inputs, this is possible in C via the `stdarg.h` library
    - Use `...` as the last argument for an arbitrary number of arguments of the last declared type
