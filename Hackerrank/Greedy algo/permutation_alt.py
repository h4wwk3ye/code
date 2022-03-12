from collections import OrderedDict
import operator
n,k=map(int,input().split())
arr=list(map(int,input().split()))
index_map=OrderedDict((v,i) for (i,v) in enumerate(arr))
#index_map=sorted(index_map,key=operator.itemgetter(0))
print(index_map)
print(index_map[2])
if k>n:
    print(arr.sort(reverse=True))
else:
    for i in range(n):
        if k==0:
            break
        else:
            index=list(index_map.values())[n-i]
            print(index)
            if(index==n):
                continue
        #    else:
