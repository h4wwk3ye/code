
for _ in range(int(input())):
    n = int(input())
    prev = 0
    current = 0
    flag = 0
    for i in range(1, n):
        for j in range(0, i):
            calc = 2**i+2**j
            prev = current
            current = calc
            if current < n:
                continue
            else:
                flag = 1
                break
        if flag == 1:
            break
    if current == n:
        print('0')
    else:
        print(min(current-n, n-prev))
