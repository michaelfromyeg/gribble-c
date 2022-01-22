# 3. Basic Types, Operators and Expressions

- We can create variables with a name
  - Watch our for reserved keywords
- There are various data types, in increasing order of size: `char`, `int`, `float`, `double`
  - Can also apply qualifiers `short`, `long`, `signed`, and `unsigned`
- Constants are values that cannot be changed
  - e.g., the `int` value `1234`, or the `float` values `123.4` or `1e-2`
  - We can also use octal with a leading `0` or hex with a leading `0x`
  - Characters are written within single quotes, e.g., `'x'`
    - Represented using ASCII codes (between 0 and 255)
    - The constant `\0` is the null character and terminates variable-length strings
  - Strings are represented with double quotes
    - Note length is `n + 1` because of the null character described above
  - Enumeration constants describe a list of labelled integers

        ```C
        enum months { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
        ```

    - (Enums are helpful because C strings can be clunky.)
- C is statically typed, so include types with variables
- Expressions can be done to do basic arithmetic; see the operator precedence (i.e., order of operations) [here](https://en.wikipedia.org/wiki/Operators_in_C_and_C++#Operator_precedence)
- There are also relational and logical operators, such as `==`
  - 0 is false and 1 is true
- Increment and decrement operators also exist (`++` and `--`)
  - `++a` (a prefix operator) means the increment happens before the value is used; `b++` (a postfix operator), means the increment happens after
- Type conversions are possible both implicitly and explicitly
  - Implicit conversion is like when a `double` gets truncated to an `int` (usually non-obviously and perhaps unintentionally)
  - Explicit conversion is done via casting using `(<type>)`
  - There are some useful built-ins for conversion, namely ascii-to-integer `atoi` and ascii-to-float `atof`
- We can define new types using `typedef`
  - The syntax works as `typedef <type> <name>`; everywhere where `<type>` was used, `<name>` may replace it
