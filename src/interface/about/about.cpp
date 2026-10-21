#include "about.h"
#include "../colors.h"
#include <iostream>
using namespace std;

void showAbout() {
  cout << BLUE << "\n=== ABOUT THE PROGRAM ===\n" << RESET;
  cout << "This program calculates a piecewise function\n";
  cout << "for x from a to b with a step h.\n\n";

  cout << BLUE << "Input parameters:\n" << RESET;
  cout << "a - starting value of x.\n";
  cout << "b - final value of x (b >= a).\n";
  cout << "h - step size (h > 0).\n";
  cout << "n - integer parameter used in the calculations (n >= 3).\n\n";

  cout << "For x < -5, the program calculates a sum.\n";
  cout << "For x >= -5, it calculates a sum of products.\n";
  cout << "The program displays x and y at each step.\n";
  cout << "Invalid input produces an error message.\n\n";

  cout << BLUE << "\n--------------- FORMULA ---------------\n" << RESET;
  cout << "If x < -5:\n";
  cout << "  y = 4 * x * SUM(i + x) - 9\n";
  cout << "  SUM: i goes from -6 to n.\n\n";
  cout << "If x >= -5:\n";
  cout << "  y = SUM(PRODUCT((i - 2*j) / (4 + x*x)))\n";
  cout << "  SUM: i goes from 1 to n + 1.\n";
  cout << "  PRODUCT: j goes from 0 to n - 3.\n\n";
  cout << "========================================\n";
}