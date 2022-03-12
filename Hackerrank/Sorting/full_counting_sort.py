import operator


def counting_sort(arr):
    counting_arr = ['']*100
    print(arr)
    for i in range(len(arr)):
        counting_arr[int(arr[i][0])] += (arr[i][1]+' ')
    print(counting_arr)
    return counting_arr


n = int(input())
arr = [list(input().split()) for _ in range(n)]
for i in range(n//2):
    arr[i][1] = '-'
result = counting_sort(arr)
for i in result:
    if i != '':
        print(i, end='')
