n, k = [int(i) for i in input().split()]
arr = [int(i) for i in input().split()]
arr.sort()
i = 0
count = 0
while i < n:
    count += 1
    pivot = arr[i]+k
    while(i < n and arr[i] <= pivot):
        # print(i)
        i += 1
    i -= 1
    # print(arr[i])
    range = arr[i]+k
    while(i < n and arr[i] <= range):
        i += 1
print(count)
