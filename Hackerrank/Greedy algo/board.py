for q in range(int(input())):
    m,n=map(int,input().split())
    cost_y=list(map(int,input().split()))
    cost_x=list(map(int,input().split()))
    cost_y.sort(reverse=True)
    cost_x.sort(reverse=True)
    i=0
    j=0
    total=0
    y_cut=1
    x_cut=1
    while(i!=m-1 and j!=n-1):
        if (cost_y[i]>=cost_x[j]):
            #total+=cost_y[i]+sum(cost_x[j:n-1])        removed these for optimizationa as sum O(n)
            total+=y_cut*cost_y[i]
            x_cut+=1
            i+=1
        else:
            #total+=cost_x[j]+sum(cost_y[i:m-1])
            total+=x_cut*cost_x[j]
            y_cut+=1
            j+=1
    while(j!=n-1):
        #total+=sum(cost_x[j:n-1])
        total+=x_cut*cost_x[j]
        j+=1
    while(i!=m-1):
        #total+=sum(cost_y[i:m-1])
        total+=y_cut*cost_y[i]
        i+=1
    print(total%(10**9+7))
