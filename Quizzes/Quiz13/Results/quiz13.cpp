#include <vector>
#include <iostream>
bool is_valid_column(const std::vector<int>& board, int column, int digit) {
    for (int i = 0; i < 9; ++i) {
        if (board[9 * column + i] == digit) {
            return false;
        }
    }
    return true;
}
