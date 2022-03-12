from statistics import median


def counting_sort(arr):
    counting_arr = [0]*201
    length = len(arr)
    for i in range(length):
        counting_arr[arr[i]] += 1
    return counting_arr


n, d = [int(i) for i in input().split()]
expenditure = [int(i) for i in input().split()]
arr = counting_sort(expenditure)

count = 0
for i in range(d, n):
    med = median(expenditure[i-1-d+1:i])
    if expenditure[i] >= 2*med:
        count += 1
print(count)
