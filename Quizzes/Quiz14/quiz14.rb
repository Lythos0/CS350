def is_valid_column(board, column, digit)
  (0...9).each do |i|
    return false if board[9 * column + i] == digit
  end
  true
end
