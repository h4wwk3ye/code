def ceil(n):
    res = int(n)
    if res == n:
        return res
    else:
        return res+1


if __name__ == '__main__':
    n, m = map(int, input().split())
    a_arr = list(map(int, input().split()))
    b_arr = list(map(int, input().split()))
    prod_arr = [a_arr[i]*b_arr[i] for i in range(n)]
    low = 0
    high = 10**18
    while low < high:
        mid = int((low+high)/2)
        # mid=(low+high)//2
        check = 0
        for i in range(n):
            if mid < prod_arr[i]:
                check += ceil((prod_arr[i]-mid)/b_arr[i])
        if check > m:
            low = mid+1
        else:
            high = mid
    print(int((low+high)/2))
    # print((low+high)//2)
