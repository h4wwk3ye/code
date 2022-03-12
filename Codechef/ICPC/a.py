for tc in range(int(input())):
    n = int(input())
    arr = [0] * n
    d = {}
    for i in range(n):
        arr[i] = list(input().split())
    for i in range(n):
        if arr[i][0] not in d:
            d[arr[i][0]] = [0, 0]
        if arr[i][1] == "1":
            d[arr[i][0]][1] += 1
        else:
            d[arr[i][0]][0] += 1
    ans = 0
    for i in d:
        ans += max(d[i][0], d[i][1])
    print(ans)

