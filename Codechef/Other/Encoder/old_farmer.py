import sys
if __name__ == '__main__':
    for _ in range(int(input())):
        n, m = map(int, input().split())
        fruit = [None]*n
        total = [0]*n
        for i in range(n):
            fruit[i] = list(map(int, sys.stdin.readline().split()))
        for i in range(n):
            total[i] = sum[fruit[i]]
        vertical_sum = [0 for _ in range(n, stop=None, step=1)]
        