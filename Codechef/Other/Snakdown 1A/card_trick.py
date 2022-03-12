if __name__ == '__main__':
    for t in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        index = 1
        i = 1
        while i < n:
            if arr[i] < arr[i-1]:
                index = i
                break
            i += 1
        if i == n:
            flag = 1
        else:
            arr_first = arr[0:index]
            arr_second = arr[index:]
            flag = 1
            for i in range(1, len(arr_second)):
                if arr_second[i] < arr_second[i-1]:
                    flag = 0
                    break
            if flag:
                ind = 0
                while arr_first[ind] <= arr_second[0]:
                    ind += 1
                if arr_second[-1] > arr_first[ind]:
                    flag = 0

        if flag:
            print('YES')
        else:
            print('NO')
