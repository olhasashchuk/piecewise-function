# Activity Diagram Description

## Formula

$$
y =
\begin{cases}
4x \displaystyle\sum_{i=-6}^{n}(i+x)-9, & x < -5, \\
\displaystyle\sum_{i=1}^{n+1}\prod_{j=0}^{n-3}
\frac{i-2j}{4+x^2}, & x \geq -5.
\end{cases}
$$

## Input Parameters

The program uses four input parameters:

| Parameter | Description |
| --- | --- |
| a | The starting value of x |
| b | The final value of x |
| h | The step used to change x |
| n | An integer that defines the loop limits |

## Input Validation

Each input value is validated separately:

- `a` must be a number.
- `b` must be a number and `b >= a`.
- `h` must be a number and `h > 0`.
- `n` must be an integer and `n > 3`.

If a value is invalid, the program displays a specific error message and asks the user to enter that value again.

## Calculation Loop

After successful validation, the program sets `x = a`.

The main loop continues while `x <= b`. If `x > b`, the algorithm terminates.

At the beginning of every iteration, `y` is initialized to `0`.

## First Expression: x < -5

The program calculates the first expression using a loop:

1. Initialize `sum = 0`.
2. Change `i` from `-6` to `n`, inclusive.
3. Add `i + x` to `sum` during each iteration.
4. Calculate `y = 4 * x * sum - 9`.

## Second Expression: x >= -5

The program calculates the second expression using nested loops:

1. Change the outer loop variable `i` from `1` to `n + 1`, inclusive.
2. For each value of `i`, initialize `p = 1`.
3. Change the inner loop variable `j` from `0` to `n - 3`, inclusive.
4. Update the product during each inner-loop iteration:

   `p = p * ((i - 2 * j) / (4 + x * x))`

5. After the inner loop, add `p` to `y`.

## Result Output and Next Step

After calculating the function, the program displays the current values of `x` and `y`.

The value of `x` is increased by the specified step:

`x = x + h`

The program checks `x <= b` again and repeats the calculation for the next value of `x`. This continues until `x > b`.