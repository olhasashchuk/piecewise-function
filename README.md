# Piecewise Function Calculator

A C++ console application that calculates a piecewise function for values of x from a to b with a step h, using Formula 1.11.

## Author

- **Student:** Olha Sashchuk
- **University:** NTU "Kharkiv Polytechnic Institute"
- **Year:** 2026

## Formula 1.11

$$
y =
\begin{cases}
4x \displaystyle\sum_{i=-6}^{n}(i+x)-9, & x < -5, \\
\displaystyle\sum_{i=1}^{n+1}\prod_{j=0}^{n-3}
\frac{i-2j}{4+x^2}, & x \geq -5.
\end{cases}
$$

The calculation starts with `x = a`. After each calculation, x is increased by h. The process continues while `x <= b`.

## Input Parameters

| Parameter | Description | Requirement |
| --- | --- | --- |
| a | Starting value of x | Must be a number |
| b | Final value of x | Must be a number; b >= a |
| h | Step size | Must be a number; h > 0 |
| n | Parameter that defines the loop limits | Must be an integer; n >= 3 |

The requirement `n >= 3` follows the implementation in laboratory work 2.

The values of a, b and h may contain decimals. Use a dot as the decimal separator.

## Functional Requirements

The application must:

- Allow the user to enter parameters manually or read them from a file.
- Validate all input parameters.
- Display an error message for invalid input.
- Ask the user to enter an invalid manual value again.
- Display parameters loaded from a file and ask for confirmation.
- Calculate the function for each value of x in the specified range.
- Display results in a table with columns for x and y.
- Save input parameters and results to a file.
- Allow the user to view program information.
- Return to the main menu after calculation.
- Allow the user to exit the application.

## Main Menu

1. Calculate function values.
2. About the program.
3. Exit.

The user enters the option number and presses Enter. Invalid input displays an error message and repeats the menu.

A short quick guide is displayed once at startup.

## Input Source Menu

1. Read from file.
2. Enter manually.
3. Return to main menu.

Selecting the third option returns to the main menu without starting a calculation.

## Manual Input

The user enters a, b, h and n.

Each value is validated separately. If a value is invalid, the program displays an error message and asks the user to enter it again.

After successful validation, the program calculates, displays and saves the results.

## File Input

The program reads parameters from `data.txt` in the following order:

    a b h n

Values must be separated by spaces or line breaks.

If the file cannot be opened, the data cannot be read, or the parameters are invalid, the program displays an error message and returns to the main menu.

After loading valid parameters, the program displays them and asks for confirmation:

- `y` or `Y` starts the calculation.
- `n` or `N` switches to manual input.
- Any other answer displays an error and repeats the question.

## Calculation Results

The program displays the current values of x and y in a console table.

The input parameters and results are also saved to `result.txt` as plain text without color codes.

Each new calculation overwrites `result.txt`. Errors when opening or writing the output file are reported to the user.

After calculation, the program returns to the main menu.

## Program Information

The About the program option displays:

- The purpose of the program.
- Input parameters and requirements.
- The formulas used for calculation.

After displaying this information, the program returns to the main menu.

## Modelling and Interface Design

The project includes:

- A Use Case Diagram showing interactions between the user and the application.
- An Activity Diagram showing input validation and the calculation algorithm.
- Console interface wireframes.
- A flowchart showing transitions between screens.
- Use case scenarios describing application behaviour.

The UML diagrams were created using Visual Paradigm. The wireframes were created using Figma.

## Technologies and Tools

- C++
- Visual Paradigm
- Figma