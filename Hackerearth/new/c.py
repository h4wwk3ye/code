for tc in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))

    if (n == 1):
        print(1)
    else:
        mx = arr[0] | arr[1]
        for i in range(2, n):
            mx = mx | arr[i]
        arr.sort(reverse=True)
        ans = 1
        curr = arr[0] | arr[1]
        m = arr[0]
        if (curr > m):
            ans += 1
        for i in range(2, n):
            if (arr[i] | arr[i-1] > curr):
                ans += 1
            curr = arr[i] | arr[i-1]
            if (curr > mx):
                break
        print(ans)
