#include "menu.h"
#include "../colors.h"
#include <iostream>
using namespace std;

void showMenu() {
  cout << "\n";
  cout << "========================================\n";
  cout << BLUE << "|         FUNCTION CALCULATOR          |\n" << RESET;
  cout << "========================================\n";
  cout << "|  1. Calculate function values        |\n";
  cout << "|  2. About the program                |\n";
  cout << "|  3. Exit                             |\n";
  cout << "========================================\n";
  cout << "\nChoose an option (1-3): ";
  cout << "\n";
}