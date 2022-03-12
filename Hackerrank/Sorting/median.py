from random import randint


def partition(arr, l, r):
    pivot_index = randint(l, r)
    pivot_value = arr[pivot_index]
    arr[pivot_index], arr[r] = arr[r], arr[pivot_index]
    print(pivot_value, pivot_index)
    store_index = l
    for i in range(l, r):
        if arr[i] < pivot_value:
            arr[store_index], arr[i] = arr[i], arr[store_index]
            store_index += 1
    arr[l], arr[store_index] = arr[store_index], arr[l]
    return store_index


def quick_select(arr, l, r, k):
    if l == r:
        return arr[l]
    current = partition(arr, l, r)
    if current == k:
        return arr[k]
    elif current > k:
        return quick_select(arr, l, current-1, k)
    else:
        return quick_select(arr, current+1, r, k)


n = int(input())
arr = list(map(int, input().split()))
k = n//2
print(quick_select(arr, 0, n-1, k))
