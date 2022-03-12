import operator
p, s = map(int, input().split())
count_array = [0]*s
for i in range(p):
    arr = []
    score = list(map(int, input().split()))
    no_of_contestatnts = list(map(int, input().split()))
    for j in range(s):
        lst = []
        lst.append(score[j])
        lst.append(no_of_contestatnts[j])
        arr.append(lst)
    # print(arr)
    arr.sort(key=operator.itemgetter(0))
    # print(arr)
    for j in range(1, s):
        if arr[j][1] < arr[j-1][1]:
            if not count_array[i]:
                count_array[i] = 1
            else:
                count_array[i] += 1
arr_list = []
for i in range(s):
    list = []
    list.append(count_array[i])
    list.append(i)
    arr_list.append(list)
arr_list.sort(key=operator.itemgetter(0))
for i in range(s):
    print(arr_list[i][1]+1)
