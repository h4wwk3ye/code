import sys
sys.setrecursionlimit(4000)


def solve(s, i):
    if output[i] != -1:
        return output[i]
    if int(s[i]) % 2 == 0:
        check = 1
    else:
        check = 0
    output[i] = check+solve(s, i+1)
    return output[i]


if __name__ == '__main__':
    s = input()
    n = len(s)
    output = [-1]*n
    if int(s[n-1]) % 2 == 0:
        output[n-1] = 1
    else:
        output[n-1] = 0
    solve(s, 0)
    print(*output)
