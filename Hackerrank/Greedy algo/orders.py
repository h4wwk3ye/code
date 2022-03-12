n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
sorted_arr=sorted(arr,key=sum)

for i in sorted_arr:
    for j in range(n):          # through array a
        if i==arr[j]:
            print(arr.index(i)+1,end=' ')
            arr[j]='flag'           # to preent same order no and serve time (case 2)
