n = int(input())
array = list(map(int, input().split()))
array.sort()
i = 1
while i < n:
    if array[i] > array[i-1]:
        array[i-1] = 0
    else:
        j = i-1
        while j >= 0:
            if array[i] > array[j] and array[j] != 0:
                array[j] = 0
                break
            j -= 1
    i += 1

print(sum(array))
