if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    length = 0
    flag = 0
    reverse_flag = 0
    if n >= 2 and arr[0] == 1 and arr[1] == 2:
        length = 1
        flag = 1
    elif n >= 2 and arr[0] != 1 and (arr[0]+1 == arr[1]):
        flag = 1
    if n >= 2 and arr[-1] == 1000 and arr[-2] == 999:
        length = 1
        reverse_flag = 1
    elif n >= 2 and arr[-1] != 1000 and (arr[-1]+1 == arr[-2]):
        reverse_flag = 1
    local_length = length
    if reverse_flag == 0:
        for i in range(1, n-1):
            if arr[i]+1 == arr[i+1] and flag == 0:
                flag = 1
            elif arr[i]+1 == arr[i+1] and flag == 1:
                local_length += 1
            else:
                local_length = 0
                flag = 0
            length = max(length, local_length)
        print(length)
    else:
        for i in range(1, n-2):
            if arr[i]+1 == arr[i+1] and flag == 0:
                flag = 1
            elif arr[i]+1 == arr[i+1] and flag == 1:
                local_length += 1
            else:
                local_length = 0
                flag = 0
            length = max(length, local_length)
        print(length)
