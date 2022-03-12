import sys


def recurse(x, y, n):
    global count
    if x < 0 or x >= 10 or y < 0 or y >= 10:
        return
    '''if board[x][y] == 1:
        return'''
    if n == 0:
        if board[x][y] == 0:
            count += 1
        board[x][y] = 1
        return
    recurse(x-1, y-2, n-1)
    recurse(x-1, y+2, n-1)
    recurse(x+1, y+2, n-1)
    recurse(x+1, y-2, n-1)
    recurse(x+2, y+1, n-1)
    recurse(x+2, y-1, n-1)
    recurse(x-2, y+1, n-1)
    recurse(x-2, y-1, n-1)


if __name__ == '__main__':
    i, j, N = map(int, input().split())
    board = [[0 for _ in range(10)] for _ in range(10)]
    global count
    count = 0
    recurse(i-1, j-1, N)
    print(count, sep=' ', end='\n', file=sys.stdout, flush=False)
