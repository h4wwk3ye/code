import sys
if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    arr = list(map(int, sys.stdin.readline().split()))
    d = {}
    maximum = 0
    count = 0
    total = 0
    for i in range(n):
        if arr[i] not in d:
            d[arr[i]] = 0
        d[arr[i]] += 1
        maximum = max(arr[i], maximum)
        if arr[i] == 1:
            count += 1
        total += arr[i]
    if maximum != 1:
        count += maximum
    if maximum < n:
        maximum = min(maximum, n-maximum)
        for i in range(2, maximum+1):
            if i in d:
                if d[i] != False:
                    count += 1
                    d[i] = False
            else:
                count += 1

    # print(count)
    print(total-count, sep=' ', end='\n', file=sys.stdout, flush=False)
