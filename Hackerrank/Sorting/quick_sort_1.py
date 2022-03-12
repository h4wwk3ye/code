def quicksort(arr):
    item = arr[0]
    left = []
    right = []
    equal = []
    for i in range(len(arr)):
        if arr[i] > item:
            right.append(arr[i])
        elif arr[i] == item:
            equal.append(arr[i])
        else:
            left.append(arr[i])
    sorted_arr = left+equal+right
    return sorted_arr


n = int(input())
arr = list(map(int, input().split()))
result = quicksort(arr)
print(*result)
