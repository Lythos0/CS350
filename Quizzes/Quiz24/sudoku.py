class Sudoku:
    def __init__(self):
        self.board = [0] * 81
        self.permanent = [False] * 81
        self.digit = 1
        self.records = []

if __name__ == '__main__':
    s = Sudoku()
