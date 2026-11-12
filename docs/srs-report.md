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
| FR-10 | The application shall start at `x = a`, evaluate Formula for each `x ≤ b`, and increase `x` by `h` after each evaluation. If `a = b`, it shall evaluate the function once. |
| FR-11 | The application shall display one row per calculated point in a console table with `x` and `y` columns. |
| FR-12 | The application shall open `result.txt` for writing before evaluating the function. It shall write the input parameters and results table as plain text. If the file cannot be opened, the application shall report the error and return to the main menu without calculating. If a write fails, it shall report the failure. |
| FR-13 | The application shall return to the main menu after completing a calculation. |
| FR-14 | When the user selects **About the program**, the application shall show its purpose, the input requirements, and the formula, then return to the main menu. |
| FR-15 | When the user selects **Exit**, the application shall display a farewell message and terminate. |

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

| Requirements | Input or action | Expected result |
| --- | --- | --- |
| FR-06, FR-10, FR-11 | Enter `a = -6`, `b = -5`, `h = 1`, `n = 3`. | The table contains two rows. For `x = -6`, `y = 1791`. For `x = -5`, `y ≈ 0.344828`. |
| FR-06, FR-07 | Enter `h = 0` in manual mode. | The application displays an error and asks for `h` again. |
| FR-08, FR-09 | Put `-6 -5 1 3` in `data.txt`, select file input, and answer `N`. | The application displays the loaded values, then prompts for manual input. |
| FR-08 | Select file input with no `data.txt` in the current working directory. | The application reports the file error and returns to the main menu. |
| FR-10, FR-12 | Enter `a = 0`, `b = 0`, `h = 1`, `n = 3` in a directory where the application can write `result.txt`. | The application displays one row with `x = 0` and `y = 2.5`. The file contains the input parameters and the same result row. |