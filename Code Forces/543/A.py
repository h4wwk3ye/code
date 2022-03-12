#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <03/Mar/2019 09:18:42 PM>


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
    n, m, k = get_ints()
    power = get_array()
    school = get_array()
    choosen = get_array()
    d = {}
    for i in range(n):
        if school[i] not in d:
            d[school[i]] = []
        d[school[i]].append(power[i])
    for i in d:
        d[i].sort()
    curr = 0
    for i in choosen:
        i -= 1
        if d[school[i]][-1] != power[i]:
            #print(i, power[i], d[school[i]])
            curr += 1
    print(curr)


if __name__ == "__main__":
    main()
