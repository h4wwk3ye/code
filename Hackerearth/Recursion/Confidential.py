import sys


def recurse(a, b):
    if b < a:
        return
    mid = (a+b)//2
    #print(a, b, mid)
    arr.append(string[mid])
    if a == b:
        return
    recurse(a, mid-1)
    recurse(mid+1, b)


if __name__ == '__main__':
    for tc in range(int(input())):
        n = int(input())
        string = input()
        # print(string)
        arr = []
        recurse(0, n-1)
        print(*arr, sep='', end='\n', file=sys.stdout, flush=False)
