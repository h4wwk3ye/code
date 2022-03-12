import operator
n,k=map(int,input().split())
contest=[]
for _ in range(n):
    contest.append(tuple(map(int,input().split())))
contest.sort(key=operator.itemgetter(0),reverse=True)
luck=0

for i in contest:
    if(i[1]==0):
        luck+=i[0]
    elif(k>0):
        luck+=i[0]
        k-=1
    else:
        luck-=i[0]
print(luck)
