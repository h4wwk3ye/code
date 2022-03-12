n=int(input())
arr=[int(input()) for _ in range(n)]
arr_1=[1]
arr_2=[1]
previous=1
for i in range(1,n):
    if arr[i]>arr[i-1]:
        previous=previous+1
        arr_1.append(previous)
    else:
        previous=1
        arr_1.append(previous)
#print(arr_1)
previous=1
arr_reverse=arr[::-1]
for i in range(1,n):
    if arr_reverse[i]>arr_reverse[i-1]:
        previous+=1
        arr_2.append(previous)
    else:
        previous=1
        arr_2.append(previous)
arr_2=arr_2[::-1]
final_list=[]
for i in range(n):
    if arr_1[i]>arr_2[i]:
        final_list.append(arr_1[i])
    else:
        final_list.append(arr_2[i])
print(sum(final_list))
