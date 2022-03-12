n, m = map(int, input().split())
arr = [0]*(n+1)
for i in range(m):
    a, b, k = map(int, input().split())
    arr[a-1] += k
    if b < n+1:
        arr[b] -= k
maximum = 0
check = 0
for i in range(n):
    check += arr[i]
    maximum = max(check, maximum)
print(maximum)
