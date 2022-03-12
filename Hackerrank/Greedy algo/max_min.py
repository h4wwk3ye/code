n=int(input())
k=int(input())
arr=[int(input()) for _ in range(n)]
arr.sort()
i=0
j=k-1
diff=None
while(j<n):
    if diff==None:
        diff=arr[j]-arr[i]
        i+=1
        j+=1
    elif arr[j]-arr[i]<diff:
        diff=arr[j]-arr[i]
        j+=1
        i+=1
    else:
        j+=1
        i+=1
print(diff)
