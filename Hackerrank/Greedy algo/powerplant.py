n, k = map(int, input().split())
arr = list(map(int, input().split()))
i = 0
flag = (k-1)
count = 0
output = 0
while(i < n):
    if arr[i] == 1:
        count += 1
        if n-1-i <= k-1:
            break
        if (i+2*(k-1)+1 < n):
            i += (2*(k-1)+1)
            flag = 2*(k-1)
        else:
            flag = n-1-i-1
            i = n-1

    else:
        if i == 0:
            i += (k-1)
        elif flag != 0:
            i -= 1
            flag -= 1
        else:
            output = -1
            break
if output == 0:
    print(count)
else:
    print(-1)
