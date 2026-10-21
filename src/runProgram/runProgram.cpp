#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include "../input/manualInput/manualInput.h"
#include "../input/fileInput/fileInput.h"
#include "../calculator/calculator.h"
#include "../interface/colors.h"

using namespace std;

void runProgram(bool fromFile) {
  double a = 0.0;
  double b = 0.0;
  double h = 0.0;
  int n = 0;

  // Read input either from file or manually.
  bool inputIsValid = false;
  if (fromFile) {
    inputIsValid = readFromFile(a, b, h, n);

    if (inputIsValid == false) {
      return;
    }

    char answer = ' ';

    while (true) {
      cout << "\nDo you want to proceed with these parameters? (y/n): ";
      cin >> answer;

      if (cin.eof()) {
        return;
      }

      // Accept only a single y / Y or n / N.
      if (cin.fail() || cin.peek() != '\n' ||
          (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')) {
        cout << RED << "\n[ERROR] Invalid choice. Please enter y or n.\n" << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }
      break;
    }

    if (answer == 'n' || answer == 'N') {
      cout << "\nPlease enter the parameters manually.\n";
      inputIsValid = readManualInput(a, b, h, n);
    }
  } else {
    inputIsValid = readManualInput(a, b, h, n);
  }

  if (inputIsValid == false) {
    return;
  }

  double x = a;

  ofstream outFile("result.txt");

  if (!outFile) {
    cout << RED << "Failed to open result.txt for writing.\n" << RESET;
    return;
  }

  outFile << "\n---------- INPUT PARAMETERS ---------\n";
  outFile << "Starting value a = " << a << '\n';
  outFile << "Final value b (b >= a) = " << b << '\n';
  outFile << "Step h (h > 0) = " << h << '\n';
  outFile << "Integer n (n >= 3) = " << n << '\n';

  cout << BLUE << "\n--------------- RESULTS ---------------\n" << RESET;
  cout << setw(10) << "x" << setw(17) << "y" << '\n';
  cout << "---------------------------------------\n";

  outFile << "\n--------------- RESULTS ---------------\n";
  outFile << setw(10) << "x" << setw(17) << "y" << '\n';
  outFile << "---------------------------------------\n";

  while (x <= b) {
    double y = calculateFunction(x, n);

    cout << setw(10) << x << setw(17) << y << '\n';
    outFile << setw(10) << x << setw(17) << y << '\n';
    x += h;
  }

  cout << "---------------------------------------\n";
  outFile << "---------------------------------------\n";
  outFile.close();

  if (!outFile) {
    cout << RED << "Error occurred while writing to result.txt.\n" << RESET;
  } else {
    cout << GREEN << "\nResult successfully written to result.txt.\n" << RESET;
  }

  cout << GREEN << "\nCalculation complete. Returning to menu.\n" << RESET;
}