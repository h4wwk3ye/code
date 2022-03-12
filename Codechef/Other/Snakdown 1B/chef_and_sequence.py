import sys
if __name__ == '__main__':
    for tc in range(int(input())):
        n, k = map(int, sys.stdin.readline().split())
        arr = list(map(int, input().split()))
        count_1 = arr.count(1)
        if n-count_1 <= k:
            print('YES', sep=' ', end='\n', file=sys.stdout, flush=False)
        else:
            print('NO', sep=' ', end='\n', file=sys.stdout, flush=False)
