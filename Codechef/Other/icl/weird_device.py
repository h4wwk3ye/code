#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <28/Mar/2019 09:16:01 PM>


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
    for tc in range(int(input())):
        k, n = input().split()
        #n = int(n)
        d = {}
        for i in k:
            if i not in d:
                d[i] = 0
            d[i] += 1
        if '0' in d:
            k = 1
        else:
            k = 0
        ans = (len(d)-k)*len(d)*len(d)
        print(ans)


if __name__ == "__main__":
    main()
