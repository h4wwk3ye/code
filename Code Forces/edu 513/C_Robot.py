import sys
from math import sqrt
if __name__ == '__main__':
    n = int(input())
    operations = list(map(int, sys.stdin.readline().split()))
    x, y = map(int, sys.stdin.readline().split())
    if sqrt(x**2+y**2) > n:
        print(-1, sep=' ', end='\n', file=sys.stdout, flush=False)
    else:
        for i in range(n):
            if operations[i] == 'U':
                if x < abs(x-1)
