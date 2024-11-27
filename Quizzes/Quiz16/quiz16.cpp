#include <vector>
using namespace std;
#include <iostream>
bool is_valid_box(int row, int column, const std::vector<std::vector<char>>& board, char digit) {
    int offset = 27 * (row / 3) + 3 * (column / 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[row / 3 * 3 + i][column / 3 * 3 + j] == digit) {
                return false;
            }
        }
    }
    return true;
}
