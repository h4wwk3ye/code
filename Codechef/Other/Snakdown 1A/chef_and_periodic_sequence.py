if __name__=='__main__':
    for t in range(int(n)):
        n=int(input())
        arr=list(map(int,input().split()))
        cnt-1=0
        for i in range(n):
            if arr[i]==-1:
                cnt-1+=1
        if cnt-1==n or cnt-1==n-1:
            print('inf')
        else:
            flag=1
            j=0
            prev=arr[0]
            while arr[j]!=-1:
                j+=1
                prev=arr[j]
            for i in range(j+1,n):
                if arr[i]>arr[j] and arr[i]-arr[j]!=i:
                    flag=0
                    break
                if arr[i]!=-1 and arr[i]<=prev:

            if flag==1:
                index=0
                curr=arr[0]
                for i in range(n):
                    if arr[i]>curr:
                        curr=arr[i]
                    if arr[i]!=-1 and arr[i]<curr:
                        index=
