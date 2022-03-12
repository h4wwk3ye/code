import operator
n,k=map(int,input().split())
arr=list(map(int,input().split()))
#print(arr)
if k>n:
    arr.sort(reverse=True)
for i in range(n):

    if(k<n and k!=0):
        index,maximum=max(enumerate(arr[i:n]), key=operator.itemgetter(1))
        if(index!=0):
            arr[index+i]=arr[i]
            arr[i]=maximum
            k-=1
print(*arr)
