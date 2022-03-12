t=int(input())
for i in range(t):
    n,a,b=map(int,input().split())
    arr=list(map(int,input().split()))
    c1=0
    c2=0
    for j in arr:
        if a==j:
            c1+=1
        if b==j:
            c2+=1
    p1=c1/n
    p2=c2/n
    print(p1*p2)
