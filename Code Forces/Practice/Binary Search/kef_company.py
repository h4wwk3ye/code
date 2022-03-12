#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <08/Mar/2019 11:42:15 PM>


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
    n, d = get_ints()
    arr = [0]*n
    for i in range(n):
        arr[i] = get_array()
    arr.sort()
    ans = 0
    j = 0
    curr = 0
    for i in range(n):
        while j < n and arr[j][0] < arr[i][0]+d:
            curr += arr[j][1]
            j += 1
        ans = max(ans, curr)
        curr -= arr[i][1]
    print(ans)


if __name__ == "__main__":
    main()
