import sys


def multiply(F, M):
    x = (((F[0][0]*M[0][0]) % mod) + ((F[0][1]*M[1][0]) % mod)) % mod
    y = (((F[0][0]*M[0][1]) % mod) + ((F[0][1]*M[1][1]) % mod)) % mod
    z = (((F[1][0]*M[0][0]) % mod) + ((F[1][1]*M[1][0]) % mod)) % mod
    w = (((F[1][0]*M[0][1]) % mod) + ((F[1][1]*M[1][1]) % mod)) % mod

    F[0][0] = x
    F[0][1] = y
    F[1][0] = z
    F[1][1] = w


def power(matrix, n):
    if n == 0 or n == 1:
        return
    res = [[1, 1], [1, 0]]
    power(matrix, n//2)
    multiply(matrix, matrix)
    if n & 1:
        multiply(matrix, res)


def fib(n):
    matrix = [[1, 1], [1, 0]]
    if n == 0:
        return 0
    power(matrix, n-1)
    return matrix[0][0]


if __name__ == '__main__':
    mod = 10**9+7
    for tc in range(int(input())):
        n = int(input())
        print(fib(n+2), sep=' ', end='\n', file=sys.stdout, flush=False)
