for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    array = [-1]*(n+1)
    for i in range(n):
        if a[i] >= 1 and a[i] <= n:
            array[a[i]] = 1
    count = 0
    for i in range(1, n+1):
        if array[i] == 1:
            count += 1
    print(n-count)
