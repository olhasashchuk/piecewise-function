#include <iostream>
#include <limits>

#include "manualInput.h"
#include "../../interface/colors.h"

using namespace std;

bool readManualInput(double &a, double &b, double &h, int &n) {
  cout << BLUE << "\n---------- INPUT PARAMETERS ----------\n" << RESET;
  cout << "Enter a number and press Enter.\n";
  cout << "Use a dot for decimals, for example: 2.5\n";
  cout << "Requirements: b >= a, h > 0, n >= 3.\n\n";
  cout << "Starting value a: ";
  cin >> a;

  // Validate a.
  while (cin.fail() || cin.peek() != '\n') {
    if (cin.eof())
      return false;

    cout << RED << "Invalid input. 'a' must be a number.\n" << RESET;
    // Reset the error state so cin can read input again.
    cin.clear();
    // Discard the rest of the input line, including the newline.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nRe-enter the a value: ";
    cin >> a;
  }

  // Validate b.
  cout << "Final value b (b >= a): ";
  cin >> b;

  while (cin.fail() || cin.peek() != '\n' || b < a) {
    if (cin.eof())
      return false;

    if (cin.fail() || cin.peek() != '\n') {
      cout << RED << "\nInvalid input. 'b' must be a number.\n" << RESET;
    } else {
      cout << RED << "\nInvalid input. 'b' must be greater than or equal to 'a'.\n" << RESET;
    };

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nRe-enter the b value: ";
    cin >> b;
  }

  // Validate h.
  cout << "Step h (h > 0): ";
  cin >> h;

  while (cin.fail() || cin.peek() != '\n' || h <= 0) {
    if (cin.eof())
      return false;

    if (cin.fail() || cin.peek() != '\n') {
      cout << RED << "\nInvalid input. 'h' must be a number.\n" << RESET;
    } else {
      cout << RED << "\nInvalid input. 'h' must be greater than 0.\n" << RESET;
    };

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nRe-enter the h value: ";
    cin >> h;
  }

  // Validate n.
  cout << "Integer n (n >= 3): ";
  cin >> n;

  while (cin.fail() || cin.peek() != '\n' || n < 3) {
    if (cin.eof())
      return false;

    if (cin.fail() || cin.peek() != '\n') {
      cout << RED << "\nInvalid input. 'n' must be an integer greater than or equal to 3.\n"
           << RESET;
    } else {
      cout << RED << "\nInvalid input. 'n' must be greater than or equal to 3.\n" << RESET;
    };

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nRe-enter the n value: ";
    cin >> n;
  }

  cout << "\n";
  cout << "\033[1mYour input parameters are:\033[0m\n";
  cout << "a = " << a << '\n';
  cout << "b = " << b << '\n';
  cout << "h = " << h << '\n';
  cout << "n = " << n << '\n';

  return true;
}
