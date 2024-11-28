def undo(self):
    if not self.records:
        return
    s = self.records.pop()
    d = int(s[0])
    p = int(s[1:])
    self.board[p] = d
