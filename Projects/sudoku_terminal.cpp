#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <random>
#include <ctime>

using namespace std;

class Sudoku {
private:
    vector<vector<int>> board;
    vector<vector<bool>> permanent;
    int digit;
    vector<tuple<int, int, int>> records;

public:
    Sudoku() : board(9, vector<int>(9, 0)), permanent(9, vector<bool>(9, false)), digit(1) {}

    string selectPuzzle() {
        vector<string> puzzles = {
             "530070000600195000098000060800060003400803001700020006060000280000419005000080079"
            "100101000110101000101000000100000001100101000001001000001000010000100101000010101",

            "800000000003600000070090200050007000000045700000100030001000068008500010090000400"
            "100000000000100000000000100000100000000010010000001000000001001000000100000000100",

            "005300000800000020070010500400005300010070006003200080060000000000030090900008007"
            "001001000100000100000000100010000000010000010001000100000000000000100000000100001",

            "020000000800450000000000700000200003600000004000006100009000000000740005000000020"
            "000000000100101000000000010000010000000000100000010001000000000101000010000000000",

            "034000600000007004000000050700500000000080000000003006040000000600100000009000320"
            "011000100000000100000000010010000000010000000010001000000000000100000000010000011"
        };

        srand(time(0));
        int idx = rand() % puzzles.size();
        return puzzles[idx];
    }

    void initialize() {
        string puzzle = selectPuzzle();
        string displayGrid = puzzle.substr(0, 81);
        string binaryGrid = puzzle.substr(81, 81);

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                board[r][c] = displayGrid[r * 9 + c] - '0';
                permanent[r][c] = binaryGrid[r * 9 + c] == '1';
            }
        }

        display();

        while (true) {
            char response;
            cout << "Select Digit(S) or Undo(U) or Quit(Q): ";
            cin >> response;
            response = toupper(response);

            if (response == 'S') {
                int row, column;
                cout << "Enter a row (0-8): ";
                cin >> row;
                while (row < 0 || row >= 9) {
                    cout << "Row Not in range. Enter again: ";
                    cin >> row;
                }

                cout << "Enter a column (0-8): ";
                cin >> column;
                while (column < 0 || column >= 9) {
                    cout << "Column Not in range. Enter again: ";
                    cin >> column;
                }

                selectDigit();
                populateCell(row, column);
                display();
            } else if (response == 'U') {
                undo();
                display();
            } else if (response == 'Q') {
                cout << "Thank You for Playing! Goodbye" << endl;
                break;
            } else {
                cout << "Invalid input. Please enter 'S', 'U', or 'Q'." << endl;
            }

            if (hasWon()) {
                cout << "Congratulations! You've won the game." << endl;
                break;
            }
        }
    }

    bool hasWon() {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (!permanent[r][c]) return false;
            }
        }
        return true;
    }

    void selectDigit() {
        cout << "Enter a digit (1-9): ";
        cin >> digit;
        while (digit < 1 || digit > 9) {
            cout << "Invalid digit. Try again: ";
            cin >> digit;
        }
    }

    bool isValidRow(int row) {
        for (int c = 0; c < 9; ++c) {
            if (permanent[row][c] && board[row][c] == digit) return false;
        }
        return true;
    }

    bool isValidColumn(int column) {
        for (int r = 0; r < 9; ++r) {
            if (permanent[r][column] && board[r][column] == digit) return false;
        }
        return true;
    }

    bool isValidBox(int row, int column) {
        int startRow = row - row % 3;
        int startColumn = column - column % 3;

        for (int r = startRow; r < startRow + 3; ++r) {
            for (int c = startColumn; c < startColumn + 3; ++c) {
                if (permanent[r][c] && board[r][c] == digit) return false;
            }
        }
        return true;
    }

    void undo() {
        if (!records.empty()) {
            auto [row, column, oldValue] = records.back();
            records.pop_back();
            board[row][column] = oldValue;
            permanent[row][column] = false;
        }
    }

    void populateCell(int row, int column) {
        if (permanent[row][column]) {
            cout << "Cell is already permanent!" << endl;
        } else if (!isValidRow(row)) {
            cout << digit << " is present in the row" << endl;
        } else if (!isValidColumn(column)) {
            cout << digit << " is present in the column" << endl;
        } else if (!isValidBox(row, column)) {
            cout << digit << " is present in the box" << endl;
        } else {
            records.push_back({row, column, board[row][column]});
            board[row][column] = digit;
            permanent[row][column] = true;
        }
    }

    void display() {
        string dash = "  ---------------------------------";
        cout << "     0  1  2    3  4  5    6  7  8" << endl;
        cout << dash << endl;

        for (int r = 0; r < 9; ++r) {
            cout << r << " :";
            for (int c = 0; c < 9; ++c) {
                if (c % 3 == 0 && c != 0) cout << "::";
                if (permanent[r][c])
                    cout << "(" << board[r][c] << ")";
                else
                    cout << "[ ]";
            }
            cout << ":" << endl;
            if ((r + 1) % 3 == 0) cout << dash << endl;
        }
    }
};

int main() {
    Sudoku s;
    s.initialize();
    return 0;
}
