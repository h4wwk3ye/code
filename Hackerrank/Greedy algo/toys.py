n=int(input())
arr=list(map(int,input().split()))
arr.sort()
count=1
smallest=arr[0]
for i in arr:
    if (smallest+4<i):
        count+=1
        smallest=i
print(count)
