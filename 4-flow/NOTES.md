# 4. Control Flow

- Loops allow for repeated logic in programs
  - For loops behave "like normal"; within the for, there is `init_expression; loop_condition; loop_expression` as usual
  - While loops just have a conditional expression
  - The almighty do-while loop just reverses the sequence of steps in the while loop
- Conditionals also are available in C
  - If statements behave like normal; we also have access to else if, and else
  - There's also the ternary operator, as in `condition ? expression1 : expression2`
  - We can also construct `switch` statements with varying cases and a closing `break`; these can replace a series of if-else statements
  - `break` also for early-exiting a loop; `continue` allows you to "pass" a given iteration of a loop
