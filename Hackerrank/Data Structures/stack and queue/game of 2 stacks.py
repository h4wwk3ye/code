if __name__ == '__main__':
    for _ in range(int(input())):
        n, m, x = map(int, input().split())
        arr_n = list(map(int, input().split()))
        arr_m = list(map(int, input().split()))
        sum = i = j = count = 0
        while(i < n and sum+arr_n[i] <= x):
            sum += arr_n[i]
            i += 1
        count = i
        while j < m and i >= 0:
            sum += arr_m[j]
            j += 1
            while sum > x and i >= 0:
                i -= 1
                sum -= arr_n[i]

            if sum <= x and i+j > count:
                count = i+j
        print(count)
