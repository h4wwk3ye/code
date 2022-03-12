if __name__ == '__main__':
    for _ in range(int(input())):
        n, m, x = map(int, input().split())
        arr_n = list(map(int, input().split()))
        arr_m = list(map(int, input().split()))
        top1 = top2 = 0
        while (top1 < n and top2 < m) and (x > arr_n[top1] or x > arr_m[top2]):
            if arr_n[top1] <= arr_m[top2]:
                x -= arr_n[top1]
                top1 += 1
            else:
                x -= arr_m[top2]
                top2 += 1
        if top1 == n and top2 < m:
            while(top2 < m):
                if arr_m[top2] >= x:
                    break
                x -= arr_m[top2]
                top2 += 1
        if top2 == m and top1 < n:
            while(top1 < n):
                if arr_n[top1] >= x:
                    break
                x -= arr_n[top1]
                top1 += 1
        print(top1+top2)
# not right approach

# ex- [17,1,1,1,1]   [8,8,4]  and x=20
