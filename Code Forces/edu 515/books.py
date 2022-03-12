import sys
from math import ceil
if __name__ == '__main__':
    for tc in range(int(input())):
        n, x, y, d = map(int, input().split())
        if abs(x-y) % d == 0:
            print((abs(x-y)//d), sep=' ', end='\n', file=sys.stdout, flush=False)
        else:
            p = float('inf')
            q = float('inf')
            if ((y-1) % d == 0):
                p = ceil((x-1)/d)
                p += ((y-1)//d)
            if ((n-y) % d == 0):
                q = ceil((n-x)/d)
                q += ((n-y)//d)
            if p != float('inf') or q != float('inf'):
                print(min(p, q))
            else:
                print(-1)
