# Use Case Scenarios

## Use Case 1: Calculate Using Manual Input

1. The user selects "1. Calculate function values".
2. The user selects "2. Enter manually".
3. The user enters valid values for `a`, `b`, `h` and `n`.
4. The program calculates and displays the results.
5. The program saves the results to `result.txt`.
6. The program returns to the main menu.

## Use Case 2: Return from the Submenu

1. The user opens the input source selection menu.
2. The user selects "3. Return to main menu".
3. The program returns to the main menu without starting a calculation.

## Use Case 3: Calculate Using File Input

1. The user selects "1. Calculate function values".
2. The user selects "1. Read from file".
3. The program reads and validates the parameters from `data.txt`.
4. The program displays the parameters and asks for confirmation.
5. The user enters `y`.
6. The program calculates, displays and saves the results.
7. The program returns to the main menu.

## Use Case 4: Reject File Parameters and Enter Values Manually

1. The user selects file input.
2. The program loads and displays valid parameters.
3. The user enters `n` at the confirmation prompt.
4. The program asks for new parameters.
5. The user enters valid values manually.
6. The program calculates, displays and saves the results.

## Use Case 5: Correct Invalid Manual Input

1. The user enters `n = 1`.
2. The program shows an error because `n` must be at least 3.
3. The program asks for a new value.
4. The user enters `n = 3`.
5. The program accepts the value and continues.

## Use Case 6: Handle a File Reading Error

1. The user selects "1. Read from file".
2. The file contains text instead of a number or has missing parameters.
3. The program shows "Error reading data from file."
4. The program returns to the main menu.

## Use Case 7: View Program Information

1. The user selects "2. About the program".
2. The program shows its purpose, parameter requirements and formula.
3. The program returns to the main menu.

## Use Case 8: Exit the Application

1. The user selects "3. Exit".
2. The program shows "Program exiting. Goodbye!"
3. The program terminates.