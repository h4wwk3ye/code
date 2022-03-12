def check(x, y):

    for i in range(N):
        for j in range(N):
            if board[x][i] == 1 or board[i][y] == 1:
                return True
            if ((i+j == x+y) or (i-j) == x-y) and board[i][j] == 1:
                return True
    return False


def n_queens(n):
    if n == 0:
        return True
    for i in range(N):
        for j in range(N):
            # print(board)
            if check(i, j):
                continue
            board[i][j] = 1
            if n_queens(n-1):
                return True
            board[i][j] = 0
    return False


if __name__ == '__main__':
    N = int(input())
    board = [[0 for i in range(N)] for j in range(N)]
    if n_queens(N):
        print('YES')
        for i in range(N):
            for j in range(N):
                print(board[i][j], end=' ')
            print()
    else:
        print('NO')
