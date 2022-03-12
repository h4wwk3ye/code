#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <01/Mar/2019 11:33:43 PM>


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
    n, q = get_ints()
    arr = get_array()
    d = {}
    index = 0
    for i in arr:
        index += 1
        if i not in d:
            d[i] = []
        d[i].append(index)

    from bisect import bisect
    for tc in range(q):
        x, y = get_ints()
        mn = inf
        if len(d[x]) > len(d[y]):
            x, y = y, x
        l = len(d[y])
        for i in d[x]:
            index = bisect(d[y], i)
            mn = min(mn, min(abs(i-d[y][index % l]), n-abs(i-d[y][index % l]),
                             abs(i-d[y][(index-1) % l]), n-abs(i-d[y][(index-1) % l]))//2)

        print(mn)


if __name__ == "__main__":
    main()
