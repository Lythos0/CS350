def undo()
  if !@records.empty?
      s = @records.pop()
      d = s[0].to_i
      p = s[1..-1].to_i
      @board[p] = d
  end
end
