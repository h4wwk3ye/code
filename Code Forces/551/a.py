#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <14/Apr/2019 04:16:30 PM>


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
    n, t = get_ints()
    arr = [0] * n
    for i in range(n):
        arr[i] = get_array()
    vis = [0] * (2 * 10**5 + 5)
    for i in range(n):
        curr = arr[i][0]
        while curr < 2 * 10**5 + 5:
            vis[curr] = i + 1
            curr += arr[i][1]
    #print(vis[10**5 - 1:10**5 + 5])
    for i in range(t, 2 * 10**5 + 5):
        if (vis[i] != 0):
            print(vis[i])
            return


if __name__ == "__main__":
    main()
