n,k=map(int,input().split())
price=list(map(int,input().split()))
price=sorted(price,reverse=True)
total=0
bought=0
for i in range(n):
    total+=((i//k)+1)*price[i]
print(total)
