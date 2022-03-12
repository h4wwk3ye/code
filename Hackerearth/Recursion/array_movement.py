import sys


def prime_divisor(n):
    if n % 2 == 0:
        return 2


def recurse(m, index):
    #print(m, index)
    if m < 0:
        return False
    if m == 0 and index == n-1:
        return True
    if index < 0 or index >= n:
        return False
    if recurse(m-1, index+arr[index]):
        return True
    if recurse(m-1, index-arr[index]):
        return True
    return False


if __name__ == '__main__':
    for tc in range(int(input())):
        n = int(input())
        arr = list(map(int, sys.stdin.readline().split()))
        m = int(input())

        if (recurse(m, 0)):
            print('YES', sep=' ', end='\n', file=sys.stdout, flush=False)
        else:
            print('NO', sep=' ', end='\n', file=sys.stdout, flush=False)
