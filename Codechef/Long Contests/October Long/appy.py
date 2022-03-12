from operator import *
import bisect
if __name__ == '__main__':
    n, m = map(int, input().split())
    a_arr = list(map(int, input().split()))  # a_arr=[1,2,3,4,5]
    b_arr = list(map(int, input().split()))  # b_arr=[1,2,3,4,5]
    if n == 1:
        print(max(0, a_arr[0]-m)*b_arr[0])
    else:
        joined_arr = []
        for i in range(n):
            a = a_arr[i]
            b = b_arr[i]
            joined_arr.append([a, b, a*b])
        # joined_arr=[[1,1,1],[2,2,4],[3,3,9],[4,4,16],[5,5,25]]
        joined_arr.sort(key=itemgetter(1))  # sorting first by b value
        joined_arr.sort(key=itemgetter(2))  # then sorting by product value
        # print(joined_arr)
        keys = [r[2] for r in joined_arr]  # keys=[1,4,9,16,25]
        while m > 0:
            maximum = joined_arr[-1][2]  # maximum=25   #-1 indicates last position
            popped = joined_arr.pop()  # popped=[5,5,25]
            keys.pop()
            second_maximum = joined_arr[-1][2]  # second_maximum=16
            if maximum == second_maximum:
                x = 1
            else:
                x = popped[0]-(joined_arr[-1][2]//popped[1])  # x=5-floor(16/5)=2
            new_a = popped[0]-x  # new_a=5-2=3
            value = new_a*popped[1]  # value=3*5=15
            # index is the righmost position where value can be inserted in sorted array 'keys'
            index = bisect.bisect_right(keys, value)
            joined_arr.insert(index, [new_a, popped[1], value])
            keys.insert(index, value)

            m -= x
        print(keys[-1])
