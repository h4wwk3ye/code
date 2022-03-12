#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <13/Jan/2019 09:23:32 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n, k = get_ints()
    arr = get_array()
    c1 = arr.count(1)
    c2 = arr.count(-1)
    mx = 0
    #print(c1, c2)
    for i in range(k):
        j = i
        x = 0
        y = 0
        while j < n:
            if arr[j] == 1:
                x += 1
            else:
                y += 1
            #print(x, y, j)
            j += k
        #curr = (c1 - x) + (c2 - y)
        #print(i, j, curr)
        curr = abs((c1 - x) - (c2 - y))

        mx = max(mx, curr)
    print(mx)


if __name__ == "__main__":
    main()
