# Run commands from the project root.
cd "$(dirname "$0")" || exit 1

# Create a folder for the compiled program.
mkdir -p build

# Compile the main function and interface files.
clang++ -std=c++17 -Wall -Wextra -pedantic \
    src/main.cpp \
    src/interface/menu/menu.cpp \
    src/interface/submenu/submenu.cpp \
    src/interface/guide/guide.cpp \
    src/interface/about/about.cpp \
    src/input/manualInput/manualInput.cpp \
    src/input/fileInput/fileInput.cpp \
    src/runProgram/runProgram.cpp \
    src/calculator/calculator.cpp \
    -o build/calculator