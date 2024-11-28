def is_valid_column(board, column, digit):
    for i in range(9):
        if board[9 * column + i] == digit:
            return False
    return True
