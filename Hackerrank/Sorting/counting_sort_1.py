def countingsort(arr):
    counting_arr = [0]*100
    for i in range(len(arr)):
        counting_arr[arr[i]] += 1
    return counting_arr


n = int(input())
arr = list(map(int, input().split()))
result = countingsort(arr)
# for i in result:
#print(i, end=' ')
for i in range(100):  # for counting sort 2
    while result[i] != 0:
        print(i, end=' ')
        result[i] -= 1
