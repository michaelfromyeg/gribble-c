# Why Program in C?

- C is a high-level language that is close to the metal; used to many other languages (including Python)
- Below is the C hello world program.

    ```C
        #include <stdio.h>

    int main(int argc, char *argv[]) {
        printf("hello world\n");
        return 0;
    }
    ```

- Syntactical rules change, but core principles stay teh same (e.g., there are standard functions, there is syntax, there is a different STL, APIs vary)
- C is good because it's fast, portable and mature; C is bad because it's small, needs skill, can be verbose
  - For calculations that take >10s, C can make a real difference (i.e., for large data sets, repeated procedures)
- Interpreted langauges are good for prototyping; C is good for performance
