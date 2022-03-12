from math import ceil
if __name__ == '__main__':
    n, m, k, l = map(int, input().split())
    flag = 1
    if n < m:
        flag = 0
    if ceil(l / m) > n:
        flag = 0

    if k == n and l != 0:
        flag = 0
    if flag == 0:
        print(-1)
    else:
        x = ceil(l / (n - k))
        if x > m:
            print(-1)
        else:
            y = (n - k) * x
            print(ceil(y / m))
