for t in range(int(input())):
    n, k = map(int, input().split())
    array = list(map(int, input().split()))
    output = []
    for i in range(n):
        if array[i] <= k:
            k -= array[i]
            output.append(1)
        else:
            output.append(0)
    print(*output, sep='')
