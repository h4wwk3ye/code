from functools import *
from operator import mul
if __name__ == '__main__':
    n, m = map(int, input().split())
    a_arr = list(map(int, input().split()))
    b_arr = list(map(int, input().split()))
    joined_arr = [None]*n
    for i in range(n):
        joined_arr[i] = [a_arr[i], b_arr[i]]
    joined_arr.sort(key=partial(reduce, mul), reverse=True)
    while m > 0:
        maximum = joined_arr[0][0]*joined_arr[0][1]
        second_maximum = joined_arr[1][0]*joined_arr[1][1]
        x = joined_arr[0][0]-(second_maximum//joined_arr[0][1])
        if x == 0:
            x = 1
        new_a = joined_arr[0][0]-x
        tmp_a = joined_arr[1][0]
        tmp_b = joined_arr[1][1]
        joined_arr[1][0] = new_a
        joined_arr[1][1] = joined_arr[0][1]
        joined_arr[0][0] = tmp_a
        joined_arr[0][1] = tmp_b
        m -= x
        print(joined_arr)
    print(joined_arr[0][0]*joined_arr[0][1])
