import sys
if __name__ == '__main__':
    for tc in range(int(input())):
        n, m, k, l = map(int, sys.stdin.readline().split())
        arr = list(map(int, sys.stdin.readline().split()))
        arr.sort()
        total = l*m
        count = 0
        for i in range(m):
            if i % l == 0:
                count -= 1
            if i ==
