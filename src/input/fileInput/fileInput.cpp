#include <fstream>
#include <iostream>

#include "fileInput.h"
#include "../../interface/colors.h"

using namespace std;

bool readFromFile(double &a, double &b, double &h, int &n) {
  ifstream inFile("data.txt");

  if (!inFile) {
    cout << RED << "Error opening file.\n" << RESET;
    return false;
  }

  inFile >> a >> b >> h >> n;

  if (inFile.fail()) {
    cout << RED << "Error reading data from file.\n" << RESET;
    return false;
  }

  // Check the allowed parameter values.
  if (b < a) {
    cout << RED << "Error: b must be greater than or equal to a.\n" << RESET;
    return false;
  }

  if (h <= 0) {
    cout << RED << "Error: h must be greater than 0.\n" << RESET;
    return false;
  }

  if (n < 3) {
    cout << RED << "Error: n must be greater than or equal to 3.\n" << RESET;
    return false;
  }

  cout << GREEN << "\n--- PARAMETERS LOADED FROM FILE ---\n" << RESET;
  cout << "Starting value a = " << a << ", \n";
  cout << "Final value b (b >= a) = " << b << ", \n";
  cout << "Step h (h > 0) = " << h << ", \n";
  cout << "Integer n (n >= 3) = " << n << '\n';
  return true;
}