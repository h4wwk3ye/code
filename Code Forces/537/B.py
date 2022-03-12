#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <03/Feb/2019 10:58:24 PM>


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
    n, k, m = get_ints()
    arr = get_array()
    arr.sort(reverse=True)
    x = sum(arr)
    avg = x / n
    while m > 0 and n > 1:
        flag = 0
        while n > 1 and arr[-1] < avg:
            node = arr.pop()
            m -= 1
            x -= node
            n -= 1
            flag = 1
        avg = x / n
        if flag == 0:
            break
    if m == 0:
        print(sum(arr) / len(arr))
        return
    l = len(arr)
    x = sum(arr)
    if m <= k * l:
        x += m
        print(x / l)
    else:
        x += (k * l)
        print(x / l)


if __name__ == "__main__":
    main()
