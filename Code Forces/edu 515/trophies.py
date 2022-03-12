import sys
if __name__ == '__main__':
    n = int(input())
    arr = list(input())
    aux_arr = [None]*n
    if arr[0] == 'G':
        aux_arr[0] = 1
    else:
        aux_arr[0] = 0
    coung_g = 0
    for i in range(1, n):
        if arr[i] == 'G':
            aux_arr[i] = aux_arr[i-1]+1
            coung_g += 1
        else:
            aux_arr[i] = 0
    # print(aux_arr)

    maximum, i, flag = 0, 0, 0
    local_max = 0

    # local_arr=aux_arr.copy()
    while i < n:
        if aux_arr[i] != 0 and flag == 0:
            local_max += 1
            i += 1
        else:
            index = i
            if i < n-1 and aux_arr[i+1] != 0:
                if flag == 0:
                    local_max += 1
                    i += 1
                    while i < n and aux_arr[i] != 0:
                        local_max += 1
                        i += 1
                        #print(local_max, i)
                    flag = 1
                    i = index
                else:
                    local_max = 0
                    flag = 0
                    i += 1
            else:
                local_max = 0
                i += 1
        maximum = max(local_max, maximum)
        #print(maximum, i)
        #i += 1
    print(maximum)
