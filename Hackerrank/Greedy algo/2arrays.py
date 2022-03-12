for _ in range(int(input())):
    n,k=map(int,input().split())
    arr_1=list(map(int,input().split()))
    arr_2=list(map(int,input().split()))
    arr_1.sort()
    arr_2.sort(reverse=True)
    flag=0
    for i in range(n):
        if (arr_1[i]+arr_2[i]<k):
            flag=1
            break
    if flag==0:
        print('YES')
    else:
        print('NO')
