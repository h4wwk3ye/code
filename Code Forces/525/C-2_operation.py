if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(n+1)
    count = 1
    for i in range(n-1, -1, -1):
        add_num = n*2-arr[i] % n-count
        # print(add_num)
        print(1, i+1, add_num)
        for j in range(i+1):
            arr[j] += add_num
        count += 1
        # print(arr)
    print(2, n, n)
