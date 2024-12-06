#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <random>
using namespace std;

// Array of Sudoku Puzzles
// Each puzzle consists of two strings: one for the grid and one for the fixed cells
string puzzles[5][2] = {
    {
        // Puzzle 1 - Grid
        "530070000600195000098000060800060003400803001700020006060000280000419005000080079",
        // Puzzle 1 - Fixed Cells
        "111111000111111000100000010100000100010111010100000010000111000000010"
    },
    {
        // Puzzle 2 - Grid
        "800000000600020000070000040000120000000000300000007000010000050000030006000000007",
        // Puzzle 2 - Fixed Cells
        "100000000110010000100000010000100000000000010000001000010000010000010"
    },
    {
        // Puzzle 3 - Grid
        "000000050800200007000000000004500000000600000000008200010000900600050004000000030",
        // Puzzle 3 - Fixed Cells
        "000000010100100000100000000100100000000100000000001010010000000010001000000010"
    },
    {
        // Puzzle 4 - Grid
        "000800400007020600030060010000900000600100008000008000080040030005060700004003000",
        // Puzzle 4 - Fixed Cells
        "000100100000010100100100010000100000100010001000001000010010010010000000100100"
    },
    {
        // Puzzle 5 - Grid
        "200000800000000040030001060070020000000000000000060080050040070090000000004100200",
        // Puzzle 5 - Fixed Cells
        "100000100000000010100001010100010000000000000000001010010010010010000000100100"
    }
};

// Function declarations for checking conflicts in rows, columns, and boxes
bool is_valid_row(const string& grid, int row, int selected_digit);
bool is_valid_col(const string& grid, int col, int selected_digit);
bool is_valid_box(const string& grid, int row, int col, int selected_digit);

// Selects a random puzzle from the available list of puzzles
string* select_puzzle(string puzzles[5][2]) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0)); // Seed the random number generator only once
        seeded = true;
    }
    int random_index = rand() % 5; // Randomly pick a puzzle index
    return puzzles[random_index]; // Return the selected puzzle (array of two strings)
}

// Function to display the current puzzle grid and available digits
void display(string puzzle[2], int selected_digit) {
    cout << "Game Grid:" << endl;

    string& grid = puzzle[0];        // Puzzle grid
    string& fixed_cells = puzzle[1]; // Fixed cells (cells that cannot be modified)

    // Loop to display the 9x9 grid, formatting it correctly
    for (size_t i = 0; i < grid.size(); i++) {
        if (i % 9 == 0 && i != 0) cout << endl; // New line after every 9 cells

        if (fixed_cells[i] == '1') {
            // Display fixed cells in parentheses
            cout << "( " << grid[i] << " ) ";
        } else {
            // Display editable cells with placeholders for empty cells
            cout << "[ " << (grid[i] == '0' ? " " : string(1, grid[i])) << " ] ";
        }
    }
    cout << endl << endl;

    // Display available digits to the player
    cout << "Digit List: ";
    for (int i = 1; i <= 9; i++) {
        // Highlight the currently selected digit
        if (i == selected_digit)
            cout << "[" << i << "] ";
        else
            cout << i << " ";
    }
    cout << endl;
}

// Variables to track the last modified cell for undo
int last_row = -1, last_col = -1; // To track the last modified cell
char last_value = '0'; // To track the last value placed in the cell

// Places the selected digit into the given cell (if valid)
void populate_cell(string puzzle[2], int row, int col, int selected_digit) {
    string& grid = puzzle[0];        // Puzzle grid
    string& fixed_cells = puzzle[1]; // Fixed cells
    int index = (row - 1) * 9 + (col - 1); // Convert (row, col) to 1D index

    // Check if the cell is fixed or already filled
    if (fixed_cells[index] == '1') {
        cout << "That cell is fixed and cannot be changed!" << endl;
    } else if (grid[index] != '0') {
        cout << "That cell is already filled!" << endl;
    } else if (!is_valid_row(grid, row, selected_digit) ||
               !is_valid_col(grid, col, selected_digit) ||
               !is_valid_box(grid, row, col, selected_digit)) {
        cout << "Invalid placement! Conflicts detected." << endl;
    } else {
        // Save the previous value before updating the cell
        last_row = row;
        last_col = col;
        last_value = grid[index];
        
        grid[index] = selected_digit + '0'; // Place the digit in the cell
        cout << "Digit placed successfully!" << endl;

        // Refresh the grid display
        display(puzzle, selected_digit);
    }
}

// Checks if placing the selected digit in the given row causes any conflict
bool is_valid_row(const string& grid, int row, int selected_digit) {
    int start_index = (row - 1) * 9; // Start of the row in the 1D array
    for (int i = start_index; i < start_index + 9; i++) {
        // If the selected digit already exists in the row, return false
        if (grid[i] == (selected_digit + '0')) {
            return false;
        }
    }
    return true; // No conflict found, valid placement
}

// Checks if placing the selected digit in the given column causes any conflict
bool is_valid_col(const string& grid, int col, int selected_digit) {
    int start_index = col - 1; // Start of the column in the 1D array
    for (int i = start_index; i < 81; i += 9) {
        // If the selected digit already exists in the column, return false
        if (grid[i] == (selected_digit + '0')) {
            return false;
        }
    }
    return true;
}

// Checks if placing the selected digit in the given 3x3 box causes any conflict
bool is_valid_box(const string& grid, int row, int col, int selected_digit) {
    int box_start_row = (row - 1) / 3 * 3; // Start row of the 3x3 box
    int box_start_col = (col - 1) / 3 * 3; // Start column of the 3x3 box

    // Loop through the 3x3 box and check for conflicts
    for (int i = box_start_row; i < box_start_row + 3; i++) {
        for (int j = box_start_col; j < box_start_col + 3; j++) {
            int index = i * 9 + j; // 1D index of the current cell
            if (grid[index] == (selected_digit + '0')) {
                return false; // Conflict found
            }
        }
    }
    return true; // No conflict found
}

// Undo the last move
void undo(string puzzle[2]) {
    if (last_row == -1 || last_col == -1) {
        cout << "No move to undo!" << endl;
        return;
    }

    // Revert the last move
    string& grid = puzzle[0];
    int index = (last_row - 1) * 9 + (last_col - 1);
    grid[index] = last_value; // Restore the previous value

    // Clear the tracking variables
    last_row = -1;
    last_col = -1;
    last_value = '0';

    cout << "Last move undone!" << endl;
}

// Initializes the game and handles user interaction
void Initialize(string puzzles[5][2]) {
    string* selected_puzzle = select_puzzle(puzzles); // Get a random puzzle
    int selected_digit = 1; // Default selected digit
    char action;

    while (true) {
        display(selected_puzzle, selected_digit); // Show puzzle grid

        // Prompt user for an action
        cout << "Welcome to the Sudoku Puzzle League! Please select an option: (S to select a digit, P to populate a cell, U to undo, Q to quit): ";
        cin >> action;

        // Handle user input for selecting a digit, populating a cell, undoing a move, or quitting the game
        if (action == 'S' || action == 's') {
            cout << "Enter the digit to select: ";
            cin >> selected_digit; 
        } else if (action == 'P' || action == 'p') {
            int row, col;
            cout << "Enter row (1-9): ";
            cin >> row;
            cout << "Enter column (1-9): ";
            cin >> col;
            populate_cell(selected_puzzle, row, col, selected_digit); // Populate cell with selected digit
        } else if (action == 'U' || action == 'u') {
            undo(selected_puzzle); // Undo the last move
        } else if (action == 'Q' || action == 'q') {
            cout << "Thanks for playing the game! See ya!" << endl;
            break; // Exit the game loop
        } else {
            cout << "Invalid option. Please try again!" << endl;
        }
    }
}

int main() {
    Initialize(puzzles);
    return 0;
}
