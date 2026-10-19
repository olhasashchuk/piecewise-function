# Console Interface Wireframes

## Interface Overview

The interface of the console application was improved to make the program easier to understand and use.

A short quick guide is displayed once at startup. It explains how to use the menus, prepare the input file and confirm loaded parameters. The main menu allows the user to calculate function values, view program information or exit.

The input submenu allows the user to choose manual input, load parameters from `data.txt` or return to the main menu. Invalid submenu input displays an error and repeats the submenu.

After loading valid parameters from a file, the program asks for confirmation. Entering `y` starts the calculation, while entering `n` switches to manual input. An invalid answer repeats the confirmation question.

For manual input, the program displays instructions and parameter requirements:

- `b >= a`
- `h > 0`
- `n >= 3`

Invalid values produce an error message and a repeated input prompt. If reading or validating file data fails, the program displays an error and returns to the main menu.

Calculation results are displayed in a table with columns for `x` and `y`. The parameters and results are saved to `result.txt` as plain text without color codes. Each new calculation overwrites the file. After calculation, the main menu is displayed again.

## Wireframes

Wireframes were created in Figma to visualize the structure and content of the console interface. They show menu options, input instructions, parameter confirmation, error messages and calculation results.

## Screen Descriptions

### Screen 1: Main Menu

Shows the available actions: calculate function values, view program information or exit. A quick guide is also displayed at startup.

### Screen 2: Input Source Selection

Lets the user choose manual input, file input or return to the main menu.

### Screen 3: Manual Input

Asks the user to enter `a`, `b`, `h` and `n` and displays the input requirements.

### Screen 4: Read from File

Shows valid parameters loaded from `data.txt` and asks for confirmation. Entering `y` starts the calculation, while entering `n` opens manual input.

### Screen 5: Invalid Input

Shows an error message and asks the user to enter the value again.

### Screen 6: File Reading Error

Shows an error when the required parameters cannot be read from the file or fail validation. The program then returns to the main menu.

### Screen 7: Output File

Shows the contents of `result.txt`: the input parameters and calculation results. This wireframe represents the output file rather than a console screen.

### Screen 8: Calculation Results

Shows the calculated values of `x` and `y` in a table and a message about saving the results.

### Screen 9: About the Program

Explains the program, input parameters and formula.

### Screen 10: Exit

Shows a goodbye message before the application closes.