from functools import *
from operator import *
import bisect
if __name__ == '__main__':
    n, m = map(int, input().split())
    a_arr = list(map(int, input().split()))
    b_arr = list(map(int, input().split()))

    joined_arr = [None]*n
    for i in range(n):
        joined_arr[i] = a_arr[i]*b_arr[i]
    joined_arr = list(enumerate(joined_arr))
    joined_arr.sort(key=itemgetter(1)
    keys=[r[1] for r in joined_arr]
    print(joined_arr)
    if n == 1:
        print(max(0, a_arr[0]-m)*b_arr[0])
    else:
        while m > 0:
            maximum=joined_arr[-1][1]
            popped=joined_arr.pop()
            keys.pop()
            second_maximum=joined_arr[-1][1]
            if maximum == second_maximum:
                print('Yes')
                x=1
            else:
                index=popped[0]
                x=a_arr[index]-(joined_arr[-1][1]//b_arr[index])
            print(joined_arr)

            index=popped[0]
            new_a=a_arr[index]-x
            a_arr[index]=new_a
            value=new_a*b_arr[index]
            new_index=bisect.bisect_left(keys, value)
            joined_arr.insert(new_index, (index, value))
            keys.insert(new_index, value)
            m -= x
            print(x, value, index)
            print(keys)
            print(joined_arr)
        print(joined_arr[-1][1])
