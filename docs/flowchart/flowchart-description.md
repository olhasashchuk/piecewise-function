# Transitions Between Screens

A flowchart was created to show navigation between the application screens.

## Startup and Main Menu

The program displays a quick guide at startup and then opens the main menu. The user can choose to:

- Calculate function values.
- View program information.
- Exit the application.

## Input Source Selection

When the user selects calculation, the input source selection menu is displayed. The user can choose file input, manual input or return to the main menu.

Invalid submenu input displays an error message and repeats the submenu.

## File Input and Confirmation

After valid parameters are loaded from `data.txt`, the program displays them and asks for confirmation:

- Entering `y` starts the calculation.
- Entering `n` switches to manual input.
- An invalid answer displays an error and repeats the confirmation question.

If reading or validating file data fails, the program displays an error and returns to the main menu.

## Manual Input

The user enters `a`, `b`, `h` and `n`.

- Valid input starts the calculation.
- Invalid input displays an error and repeats the prompt for the incorrect value.

## Calculation Results

The program displays the calculation results and a message about saving them to `result.txt`. It then returns to the main menu.

## Program Information and Exit

After displaying program information, the program returns to the main menu.

Selecting Exit displays a goodbye message and terminates the application.