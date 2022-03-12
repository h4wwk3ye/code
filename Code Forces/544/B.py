#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <07/Mar/2019 09:46:59 PM>


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
    n, k = get_ints()
    arr = get_ints()
    d = {}
    for i in arr:
        if i % k not in d:
            d[i % k] = 0
        d[i % k] += 1
    ans = 0
    if 0 in d:
        ans += ((d[0]//2)*2)
    for i in d:
        if (k-i) in d:
            if i == k-i:
                ans += (d[i]//2)*2
            else:
                ans += min(d[i], d[k-i])

    print(ans)


if __name__ == "__main__":
    main()
