#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <05/May/2019 12:10:01 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


# ///==========MAIN=============///


def main():
    n, k = get_ints()
    d = {}
    arr = [0] * (n + 1)
    flag = [False] * (n + 1)
    inp = get_array()
    ans = 0
    for i in range(k):
        p = inp[i]
        #p -= 1
        arr[p] += 1
        d[p] = 1

    for i in range(k):
        p = inp[i]
        if flag[p] == True:
            arr[p] = max(0, arr[p] - 1)
            continue
        ans -= 1
        if p > 1:
            if arr[p - 1] != 0:
                ans -= 1
        if p < n:
            if arr[p + 1] != 0:
                ans -= 1
        arr[p] = max(arr[p] - 1, 0)
        flag[p] = True

    #ans = 0

    ans += (3 * (n - 2) + 4)
    if (ans < 0):
        ans = 0

    print(ans)


if __name__ == "__main__":
    main()
