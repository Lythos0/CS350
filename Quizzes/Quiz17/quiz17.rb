def is_valid_box(row, column, board, digit)
  start_row = (row / 3) * 3
  start_col = (column / 3) * 3
  (0...3).each do |i|  
    (0...3).each do |j|             
      if board[start_row + i][start_col + j] == digit
        return false                
      end
    end
  end

  true                              
end
