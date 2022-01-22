# Complex Types

- Arrays are an ordered set of items
  - Defined as `<type> <var>[<size>]`; we can index the individual elements
  - Not that indexing begins at 0
  - Values are initialized to whatever junk lived in memory from before
  - C allows us to index out of bounds
  - "Indexing" is really just shifting the array's pointer by `sizeof(<type>) * <size>`, so `arr[0] == *(arr + 0)`, etc.
  - Need to be careful, especially when writing _to_ the array
  - Arrays can be initialized by `<type> <var>[<size>] = { item1, item2, ..., itemN }` where $\text{N} \le \text{size}$
  - Two-dimensional arrays are possible too; just chain the square-brackets with each dimension's size
    - Matrix algebra can be handled by a GNU scientific library
  - Variable-length arrays are also possible
- Command-line arguments are also accessible in C programs
  - `int argc`, passed to `main`, is the number of command-line arguments passed to the program, plus one (for the name of the executable)
  - `char *argv[]` is a one-dimensional array of _strings_
  - You can use `atoi()` ("ascii-to-integer") to convert convert line arguments to their number representation
- Structures are ways of packing together groups of a data, such as an (x, y) coordinate
  - They indicated by the `struct` keyword

    ```C
    struct Point3D {
        int x;
        int y;
        int z;
    }
    ```

  - The fields can be accessed via dot notation
  - `typedef` can be used to shorten struct names

    ```C
    typedef struct {
        int x;
        int y;
        int z;
    } Point3D; // can refer to as simply "Point3D"
    ```

  - Likewise, you can create arrays of structs

