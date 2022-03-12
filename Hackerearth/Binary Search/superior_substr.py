#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <01/Mar/2019 04:19:54 PM>


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
    from collections import Counter
    for tc in range(int(input())):
        n = int(input())
        s = list(input().strip())
        x = Counter(s)
        mx = -1
        maxi = 0
        for i in x:
            if x[i] > mx:
                mx = x[i]
                maxi = i
        for p in range(n):
            if s[p] == maxi:
                s[p] = 1
            else:
                s[p] = -1
        curr, mx = 0, 0
        total = 0
        for i in range(n):
            if total+s[i]+1 >= 0:
                curr += 1
                mx = max(mx, curr)
            else:
                curr = 0
        print(mx)


if __name__ == "__main__":
    main()
