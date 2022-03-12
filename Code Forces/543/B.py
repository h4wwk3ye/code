#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <03/Mar/2019 10:09:17 PM>


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
    d = {}
    for i in range(n):
        for j in range(i+1, n):
            if arr[i]+arr[j] not in d:
                d[arr[i]+arr[j]] = 0
            d[arr[i]+arr[j]] += 1
    mx = 0
    # print(d)
    for i in d:
        mx = max(mx, d[i])
    print(mx)


if __name__ == "__main__":
    main()
