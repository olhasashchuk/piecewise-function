# Use Case Diagram Description

## Actor and Main Use Cases

The Use Case Diagram represents the interaction between the user and the application.

The diagram contains one actor: **User**.

The user interacts with two main use cases:

- Input data.
- Calculate result.

## Input Data

The Input data use case allows the user to provide the values of `a`, `b`, `h` and `n`.

Input data can be provided in two ways:

- Input data from keyboard.
- Input data from file.

In this diagram, these use cases extend Input data to represent alternative ways of providing the required values.

## Validate Input Data

The Input data use case includes Validate input data.

The application checks that:

- `a`, `b` and `h` are numbers.
- `n` is an integer.
- `b >= a`.
- `h > 0`.
- `n >= 3`.

## Display Error Message

The Display error message use case extends Validate input data when an input value is invalid.

The application displays a specific error message. For manual input, it asks the user to enter the incorrect value again. If file input fails validation, the program returns to the main menu.

## Calculate Result

The Calculate result use case calculates the function for each value of `x` in the specified range.

It includes the following use cases:

| Use Case | Description |
| --- | --- |
| Display result | Displays the calculated values of x and y |
| Save result to file | Saves the calculation results to an external file |
| Show result for each step | Shows the result for each value of x from a to b with step h |

## Relationships

- **Include** means that a use case is a required part of another use case.
- **Extend** represents optional or conditional behaviour.