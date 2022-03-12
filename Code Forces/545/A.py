#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <08/Mar/2019 02:44:36 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    x, y = 1, 0
    mx = 0
    flag = 0
    prev = arr[0]
    for i in range(1, n):
        if (arr[i] == prev):
            if flag == 0:
                x += 1
            else:
                y += 1
        else:
            flag = 1
            y = 1
            prev = arr[i]
        mx = min(x, y)
    print(mx*2)


if __name__ == "__main__":
    main()
