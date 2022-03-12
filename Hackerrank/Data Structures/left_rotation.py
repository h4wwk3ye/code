n, d = map(int, input().split())
arr = list(map(int, input().split()))
d = d % n
print(*arr[d:n], *arr[0:d])
