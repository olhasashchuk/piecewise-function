# Software Requirements Specification

**Project:** Piecewise Function Calculator  
**Author:** Olha Sashchuk  
**Version:** 1.0

## 1. Purpose

This document describes the requirements for a C++ console application that evaluates the piecewise function given in Formula:
$$
y =
\begin{cases}
4x \displaystyle\sum_{i=-6}^{n}(i+x)-9, & x < -5, \\
\displaystyle\sum_{i=1}^{n+1}\prod_{j=0}^{n-3}
\frac{i-2j}{4+x^2}, & x \geq -5.
\end{cases}
$$

The user provides a starting value, an upper bound, a step size, and an integer parameter. The application calculates the corresponding function values, displays them in the console, and saves them to a text file.

### 1.1 Definitions

| Term | Meaning |
| --- | --- |
| SRS | Software Requirements Specification |
| `a` | Starting value of `x` |
| `b` | Upper bound for `x` |
| `h` | Positive step between successive values of `x` |
| `n` | Integer parameter that determines the limits of the sums and product |
| `x` | Function argument |
| `y` | Calculated function value |

### 1.2 System overview

The application provides a main menu and a menu for selecting the input source. The user can enter values manually or load them from a file. After validating the input, the application evaluates the function, displays the results, saves them, and returns to the main menu.

### 1.3 References

1. Laboratory Work No. 4, *Creating of Software Requirement Specification*, course guidelines by Karina Melnyk, NTU “Kharkiv Polytechnic Institute”, 2026.
2. IEEE Std 830-1998. Recommended Practice for Software Requirements Specifications
3. [Project repository](https://github.com/olhasashchuk/piecewise-function)

## 2. Overall description

### 2.1 Product perspective

| Interface or constraint | Description |
| --- | --- |
| System interfaces | The application runs locally and uses the operating system's console and file system. |
| User interfaces | The user interacts with numbered menus, prompts, error messages, and a results table. |
| Hardware interfaces | The user enters data with a keyboard and reads output on a display. |
| Software interfaces | The application uses the C++ standard library and reads and writes plain-text files. |
| Communication interfaces | Not applicable. The application operates offline. |
| Memory constraints | The assignment specifies no fixed memory limit. |

### 2.2 Design constraints

**Operations.** The application shall run as a C++ console program and use Formula. Each calculation that opens the output file for writing replaces its previous contents.

**Site adaptation requirements.** Not applicable. The application requires no site-specific configuration.

### 2.3 Product functions

- Entering or loading parameters;
- Validating input:
- Calculating function values;
- Displaying and saving results:
- Viewing program information;
- Exiting the application.

### 2.4 User characteristics

The application is intended for a user who can enter numbers and choose options in a terminal. The user follows the startup guide and the prompts.

### 2.5 Constraints, assumptions and dependencies

A compatible C++ compiler and standard library are required to build the application. File input requires a readable `data.txt` in the current working directory. Saving results requires permission to create or overwrite `result.txt` in that directory. Decimal values use a dot as the decimal separator.

## 3. Specific requirements

### 3.1 External interface requirements

| Interface | Format |
| --- | --- |
| Console input | Numbered menu choices, one parameter per prompt for manual input, and a single letter for file confirmation |
| Console output | Startup guide, menus, prompts, messages, and a table with `x` and `y` columns |
| `data.txt` | Four values in the order `a b h n`, separated by whitespace |
| `result.txt` | Plain text containing the four input parameters and a table with `x` and `y` columns |

### 3.2 Functional requirements

| ID | Requirement |
| --- | --- |
| FR-01 | The application shall show a short guide once at startup. |
| FR-02 | The main menu shall offer **Calculate function values**, **About the program**, and **Exit**. |
| FR-03 | The input source menu shall allow the user to read from a file, enter values manually, or return to the main menu without starting a calculation. |
| FR-04 | When the user enters an invalid menu choice, the application shall display an error and show the same menu again. |
| FR-05 | In manual mode, the application shall prompt for `a`, `b`, `h`, and `n` in that order. |
| FR-06 | The application shall require numeric values for `a`, `b`, and `h`, with `b ≥ a` and `h > 0`. It shall require an integer `n ≥ 3`. These rules apply to both input modes. |
| FR-07 | If a manually entered value is invalid, the application shall display an error and ask the user to enter that parameter again. |
| FR-08 | In file mode, the application shall read the parameters from `data.txt` in the order specified in Section 3.1. If it cannot open or read the file, or if a parameter fails validation, it shall display an error and return to the main menu without calculating. |
| FR-09 | After loading valid file parameters, the application shall display them and ask for confirmation. It shall proceed on `y` or `Y`, switch to manual input on `n` or `N`, and repeat the prompt with an error for any other response. |
| FR-10 | The application shall start at `x = a` and evaluate Formula for each value of `x` while `x <= b`, increasing `x` by `h` after each evaluation. If `a = b`, the application shall evaluate the function once. |
| FR-11 | If `x < -5`, the application shall calculate the sum of `i + x` for `i` from `-6` to `n`, inclusive. It shall then calculate `y = 4 * x * sum - 9`. |
| FR-12 | If `x >= -5`, the application shall calculate a product for each `i` from `1` to `n + 1`, inclusive. Each product shall contain the factors `(i - 2 * j) / (4 + x * x)` for `j` from `0` to `n - 3`, inclusive. The application shall add all the products to obtain `y`. |
| FR-13 | The application shall display one row per calculated point in a console table with `x` and `y` columns. |
| FR-14 | The application shall open `result.txt` for writing before evaluating the function. It shall write the input parameters and results table as plain text. If the file cannot be opened, the application shall report the error and return to the main menu without calculating. If a write fails, it shall report the failure. |
| FR-15 | The application shall return to the main menu after completing a calculation. |
| FR-16 | When the user selects **About the program**, the application shall show its purpose, the input requirements, and the formula, then return to the main menu. |
| FR-17 | When the user selects **Exit**, the application shall display a farewell message and terminate. |

## Detailed Calculation Requirements

### FR-10 Calculate Function Values Over a Range

- **Type:** Functional
- **Priority:** High
- **Source:** Laboratory assignment, Formula
- **Description:** The application shall start at `x = a`. For each `x <= b`, it shall select the applicable branch of Formula, calculate `y`, and increase `x` by `h`. It shall stop when the next value of `x` exceeds `b`.
- **Rationale:** The user needs function values at the points defined by the selected range and step.
- **Preconditions:** The calculation has been requested, the input values have passed validation, and `b >= a`, `h > 0`, and `n >= 3`.
- **Inputs:** `a` (start), `b` (end), `h` (step), and `n` (integer parameter).
- **Expected Result:** One `(x, y)` pair is calculated for every point reached by the step within the range.
- **Dependencies:** Input validation, FR-11, and FR-12.
- **Status:** Implemented

**Acceptance Criteria**

1. Given `a = -6`, `b = -4`, `h = 1`, and `n = 3`, the application shall calculate three values, for `x = -6`, `x = -5`, and `x = -4`, in that order.
2. Given `a = 0`, `b = 5`, `h = 2`, and `n = 3`, the application shall calculate values for `x = 0`, `x = 2`, and `x = 4`. It shall not calculate a value for `x = 5` or `x = 6`.
3. Given `a = b = -5`, `h = 1`, and `n = 3`, the application shall calculate exactly one value using FR-12.

### FR-11 Calculate the First Branch

- **Type:** Functional
- **Priority:** High
- **Source:** Laboratory assignment, Formula, first branch
- **Description:** When `x < -5`, the application shall add the terms `i + x` for every integer `i` from `-6` through `n`. It shall calculate `y = 4 * x * sum - 9`, where `sum` is the sum of those terms.
- **Rationale:** Formula defines this expression for every calculation point below `-5`.
- **Preconditions:** FR-10 has selected a value of `x < -5`, and `n` is a validated integer with `n >= 3`.
- **Inputs:** The current value of `x` and the parameter `n`.
- **Expected Result:** One value of `y` for the current `x`, calculated using the first branch.
- **Dependencies:** Input validation and the current calculation point provided by FR-10.
- **Status:** Implemented

**Acceptance Criteria**

1. The sum shall include both endpoint terms, for `i = -6` and `i = n`.
2. Given `x = -6` and `n = 3`, the sum shall be `-75`, and the application shall calculate `y = 1791`.

### FR-12 Calculate the Second Branch

- **Type:** Functional
- **Priority:** High
- **Source:** Laboratory assignment, Formula, second branch
- **Description:** When `x >= -5`, the application shall calculate one product for each integer `i` from `1` through `n + 1`. Each product shall include the factor `(i - 2 * j) / (4 + x * x)` for every integer `j` from `0` through `n - 3`. The application shall add all the products to obtain `y`.
- **Rationale:** Formula defines this expression for calculation points at or above `-5`.
- **Preconditions:** FR-10 has selected a value of `x >= -5`, and `n` is a validated integer with `n >= 3`.
- **Inputs:** The current value of `x` and the parameter `n`.
- **Expected Result:** One value of `y` for the current `x`, calculated using the second branch.
- **Dependencies:** Input validation and the current calculation point provided by FR-10.
- **Status:** Implemented

**Acceptance Criteria**

1. Given `x = -5` and `n = 3`, the application shall use the second branch. Each product shall contain one factor (`j = 0`), and the result shall be `10 / 29` before rounding.
2. Given `x = 0` and `n = 4`, the application shall calculate five products, each with two factors (`j = 0` and `j = 1`). The result shall be `1.5625`.

**Formula**

$$
y =
\begin{cases}
4x \displaystyle\sum_{i=-6}^{n}(i+x)-9, & x < -5, \\
\displaystyle\sum_{i=1}^{n+1}\prod_{j=0}^{n-3}
\frac{i-2j}{4+x^2}, & x \geq -5.
\end{cases}
$$

### 3.3 Performance requirements

The application shall write results one row at a time as they are calculated. The assignment specifies no numerical response-time target.

### 3.4 Logical database requirements

Not applicable. Input and output use local text files.

### 3.5 Software system attributes

| Attribute | Requirement or scope |
| --- | --- |
| Reliability | Invalid parameters and file errors shall produce error messages as specified in FR-07, FR-08, and FR-12. |
| Availability | The application shall support local use without an internet connection. |
| Security | The application shall use the local file permissions of the operating system. |
| Maintainability | The source code shall separate calculation, input handling, and the console interface into modules. |
| Portability | The application shall use standard C++ facilities for calculation and file operations. Console colors depend on terminal support for ANSI escape sequences. |

### 3.6 Environment characteristics

**Hardware.** A computer capable of running a C++ console application.

**Peripherals.** A keyboard for input and a display for console output.

### 3.7 Verification examples

For successful calculation tests, run the application in a directory where it can create or overwrite `result.txt`.

| Requirements | Input or action | Expected result |
| --- | --- | --- |
| FR-10, FR-11, FR-12, FR-13 | Enter `a = -6`, `b = -5`, `h = 1`, and `n = 3`. | The console table contains exactly two rows, in this order: `x = -6` with `y = 1791`, and `x = -5` with `y ≈ 0.344828`. The second branch is used at `x = -5`. |
| FR-10, FR-13 | Enter `a = 0`, `b = 5`, `h = 2`, and `n = 3`. | The console table contains exactly three rows, in this order: `x = 0`, `x = 2`, and `x = 4`. There is no row for `x = 5` or `x = 6`. |
| FR-06, FR-07 | Enter `h = 0` in manual mode. | The application displays an error and asks the user to enter `h` again. |
| FR-08, FR-09 | Put `-6 -5 1 3` in `data.txt`, select file input, and answer `N` at the confirmation prompt. | The application displays the loaded values, then switches to manual input without calculating with the file values. |
| FR-08 | Select file input when `data.txt` is missing from the current working directory. | The application displays a file error and returns to the main menu without calculating. |
| FR-10, FR-12, FR-13, FR-14 | Enter `a = 0`, `b = 0`, `h = 1`, and `n = 3`. | The console table contains exactly one row: `x = 0`, `y = 2.5`. The `result.txt` file contains the four input parameters and the same result row. |
| FR-12, FR-13 | Enter `a = 0`, `b = 0`, `h = 1`, and `n = 4`. | The console table contains one row with `x = 0` and `y = 1.5625`. This verifies the second branch when each product contains two factors. |