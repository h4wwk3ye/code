
if __name__ == '__main__':
    for t in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        arr_flag_2 = dict()
        arr_flag_0 = dict()
        count_2 = 0
        count_0 = 0
        for i in range(n):
            curr_xor_2 = arr[i] ^ 2
            if curr_xor_2 in arr_flag_2:
                count_2 += arr_flag_2[curr_xor_2]

            if arr[i] not in arr_flag_2:
                arr_flag_2[arr[i]] = 0

            arr_flag_2[arr[i]] += 1
        for i in range(n):
            curr_xor_0 = arr[i]  # arr[i]^0
            if curr_xor_0 in arr_flag_0:
                count_0 += arr_flag_0[curr_xor_0]

            if arr[i] not in arr_flag_0:
                arr_flag_0[arr[i]] = 0

            arr_flag_0[arr[i]] += 1
        count_even = 0
        count_odd = 0
        for element in arr:
            if element % 2 == 0:
                count_even += 1
            else:
                count_odd += 1
        no_of_odd_xor = count_even*count_odd
        no_of_even_xor = ((n-1)*n//2)-no_of_odd_xor
        print(no_of_even_xor-count_2-count_0)
