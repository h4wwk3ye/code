n,k=map(int,input().split())
arr=list(map(int,input().split()))
arr=sorted(arr)
count=0
for items in arr:
    if items<k:
        count+=1
        k-=items
    else:
        break
print(count)
