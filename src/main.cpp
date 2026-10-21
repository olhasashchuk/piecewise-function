#include <fstream>  // For file input and output operations
#include <iomanip>  // For input/output manipulators like setprecision
#include <iostream> // For standard input and output streams
#include <limits>   // For numeric limits used in input validation

#include "interface/menu/menu.h"
#include "interface/submenu/submenu.h"
#include "interface/guide/guide.h"
#include "interface/about/about.h"
#include "runProgram/runProgram.h"
#include "interface/colors.h"
using namespace std;



int main() {
  int choice = 0;

  showInstructions();

  while (choice != 3) {
    showMenu();
    cin >> choice;

    if (cin.eof())
      return 0;

    if (cin.fail() || cin.peek() != '\n') {
      cout << RED << "Invalid input. Enter an integer from 1 to 3.\n" << RESET;

      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      choice = 0;
      continue;
    }

    // Remove the newline after valid input.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
      case 1: {

        while (true) {
          selectVariantInputData();
          int inputChoice = 0;
          cin >> inputChoice;

          if (cin.eof())
            return 0;

          if (cin.fail() || cin.peek() != '\n') {
            cout << RED << "Invalid input. Enter an integer from 1 to 3.\n" << RESET;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            inputChoice = 0;
            continue;
          }

          if (inputChoice == 1) {
            runProgram(true);
          } else if (inputChoice == 2) {
            runProgram(false);
          } else if (inputChoice == 3) {
            break;
          } else {
            cout << RED
                 << "\n[ERROR] Invalid choice. Choose an option from 1 to 3. \nReturning to menu.\n"
                 << RESET;
            continue;
          }

          if (cin.eof())
            return 0;
          break;
        }

        break;
      }

      case 2:
        showAbout();
        break;

      case 3:
        cout << GREEN << "Program exiting. Goodbye!\n" << RESET;
        break;

      default:
        cout << RED << "Choose an option from 1 to 3.\n" << RESET;
    }
  }

  return 0;
}