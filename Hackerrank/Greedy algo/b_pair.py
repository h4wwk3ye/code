if __name__=='__main__':
    n=int(input())
    lst_a=list(map(int,input().split()))
    lst_b=list(map(int,input().split()))
    bucket_a=[0]*(10**3+1)
    for i in lst_a:
        bucket_a[i]+=1          #bucket algorithm (making those incdices 1 whose values are present in a)
    #print(bucket_a)
    beautiful_pair=0
    for i in lst_b:
        if bucket_a[i]>0:
            bucket_a[i]-=1
            beautiful_pair+=1
    if beautiful_pair==n:
        beautiful_pair-=1
    else:
        beautiful_pair+=1
    print(beautiful_pair)
