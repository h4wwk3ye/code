for i in range(50):
    ans = []
    for j in range(10):
        if i & (1 << j):
            ans.append(1)
        else:
            ans.append(0)
    ans.reverse()
    print(*ans, sep="")
