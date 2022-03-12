#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <06/Apr/2019 08:28:18 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def check(n, x):
    a = sorted(arr[:n], reverse=True)
    # print(a)
    c = 0
    for i in range(n):
        if c == 0:
            if a[i] > x:
                return False
            c = 1-c
        else:
            if a[i] <= x:
                x -= max(a[i-1], a[i])
            else:
                return False
            c = 1-c
    return True


def main():
    global h, arr
    n, h = get_ints()
    arr = get_array()

    low = 0
    high = n
    while (low < high):
        mid = (low+high+1)//2
        if (check(mid, h) == True):
            low = mid
        else:
            high = mid-1
        #print(low, high, mid)
    print(low)


if __name__ == "__main__":
    main()
