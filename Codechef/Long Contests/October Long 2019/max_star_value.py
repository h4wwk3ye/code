from math import sqrt

for tc in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    cnt = [0] * (10 ** 6 + 1)
    for i in range(n):
        x = arr[i]
        if x == 1:
            ans = max(ans, i)
            continue
        d = set()
        d.add(x)
        ans = max(ans, cnt[x])
        while x % 2 == 0:
            d.add(x // 2)
            d.add(2)
            x //= 2
        for j in range(3, int(sqrt(x)) + 10, 2):
            while x % j == 0:
                d.add(j)
                d.add(x // j)
                x //= j
        if x > 2:
            d.add(x)
        # print(d)
        for j in d:
            cnt[j] += 1
    # print(cnt[:30])
    print(ans)
