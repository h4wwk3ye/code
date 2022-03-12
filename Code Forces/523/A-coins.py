import sys
if __name__ == '__main__':
    n, s = map(int, sys.stdin.readline().split())
    count = 0
    count += s//n
    if s % n != 0:
        count += 1
    print(count, sep=' ', end='\n', file=sys.stdout, flush=False)
