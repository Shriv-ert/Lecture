def isSafe(board: list[int], row: int, col: int) -> bool:
    # cek kolom kanan atas
    for i in range(row):
        if board[i] == col:
            return False
        # cek diagonal kanan atas
        if abs(board[i] - col) == abs(i - row):
            return False
    return True

def backtrack(row: int) -> None:
    if row == n:
        # konversi solusi dalam bentuk papan
        solution: list[str] = []
        for i in range(n):
            line = ['.'] * n
            line[board[i]] = 'Q'
            solution.append(''.join(line))
        res.append(solution)
        return
    for col in range(n):
        if isSafe(board, row, col):
            board[row] = col
            backtrack(row + 1)
            board[row] = -1  # backtrack