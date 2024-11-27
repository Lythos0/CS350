def is_valid_box(row, column, board, digit):
    start_row = (row // 3) * 3
    start_col = (column // 3) * 3
    for i in range(3):                  
        for j in range(3):             
            if board[start_row + i][start_col + j] == digit:
                return False           
    return True                        
