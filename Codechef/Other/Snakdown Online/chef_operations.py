if __name__ == '__main__':
    for t in range(int(input())):
        n = int(input())
        arr_a = list(map(int, input().split()))
        arr_b = list(map(int, input().split()))
        if n == 1 or n == 2:
            if arr_a == arr_b:
                print('TAK')
            else:
                print('NIE')
        else:
            index = 0
            flag = 1
            while index < n-2:
                if arr_a[index] == arr_b[index]:
                    index += 1
                    continue
                if arr_b[index] < arr_a[index]:
                    flag = 0
                    break

                diff = arr_b[index]-arr_a[index]
                arr_b[index] -= diff
                arr_b[index+1] -= (2*diff)
                arr_b[index+2] -= (3*diff)
                # print(index)
            if arr_a[index] != arr_b[index] or arr_a[index+1] != arr_b[index+1]:
                flag = 0
            if flag == 1:
                print('TAK')
            else:
                print('NIE')
