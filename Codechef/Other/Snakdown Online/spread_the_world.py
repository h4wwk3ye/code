if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        sum_arr = [0]*n
        sum_arr[0] = arr[0]
        for i in range(1, n):
            sum_arr[i] = sum_arr[i-1]+arr[i]
        completed = 1
        index = 0
        days = 1
        prev_index = 0
        while True:
            #print(index, sum_arr[index])
            if index+sum_arr[index] >= n-1:
                break
            index += sum_arr[index]
            days += 1
        print(days)
