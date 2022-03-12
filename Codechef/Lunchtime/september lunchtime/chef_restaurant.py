import bisect
import operator


def binary_search(hotel_time, element, n):
    wait = 10**9+1
    mid_node = None
    l = 0
    r = n-1
    while True:
        if l > r:
            break
        mid_node = (l+r)//2
        if element < hotel_time[mid_node][1]:
            _wait = hotel_time[mid_node][0]-element
            if _wait < wait:
                wait = _wait
            if wait < 0:
                wait = 0
                break
            r = mid_node-1
        else:
            l = mid_node+1
    if wait != 10**9+1:
        return wait
    else:
        return -1


for t in range(int(input())):
    n, m = map(int, input().split())
    hotel_time = []
    for i in range(n):
        l, r = map(int, input().split())
        tup = (l, r)
        bisect.insort_left(hotel_time, tup)
    customers = []
    for i in range(m):
        customers.append(int(input()))
    # print(hotel_time)
    waiting_time = [-1]*m
    for i in range(m):
        waiting_time[i] = binary_search(hotel_time, customers[i], n)
    print(*waiting_time, sep='\n')
