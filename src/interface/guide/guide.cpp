#include "guide.h"
#include "../colors.h"
#include <iostream>
using namespace std;


void showInstructions() {
  cout << BLUE << "\n---------- QUICK GUIDE ----------\n" << RESET;
  cout << "Choose a menu option by typing its number\n";
  cout << "and pressing Enter.\n\n";

  cout << "For file input, prepare data.txt with four values\n";
  cout << "in this order: a b h n.\n";
  cout << "Enter y to use the loaded values or n to enter your own.\n\n";

  cout << "For manual input, enter one value at a time.\n\n";

  cout << "Each calculation overwrites result.txt.\n";
  cout << "---------------------------------\n";
}