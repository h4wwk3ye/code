#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <07/Feb/2019 08:00:07 PM>


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
    n, m = get_ints()
    arr = get_array()
    arr.sort()
    check = [0] * (n + 1)
    for i in arr:
        check[i] += 1
    count = 0
    print(check)
    for i in range(1, n + 1):
        if check[i] > 0:
            if i + 1 <= n and i + 2 <= n and check[i + 1] > 0 and check[i + 2] > 0:
                print(check[i], check[i + 1], check[i + 2])
                x = min(check[i], check[i + 1], check[i + 2])
                count += x
                check[i] -= x
                check[i + 1] -= x
                check[i + 2] -= x
            if check[i] >= 3:
                x = check[i] // 3
                count += x
    print(count)


if __name__ == "__main__":
    main()
