#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <21/Mar/2019 09:08:18 PM>


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
    s = input().strip()
    ans = 0
    for i in range(n):
        if int(s[i]) % 2 == 0:
            ans += 1
            ans += (i)
    print(ans)


if __name__ == "__main__":
    main()
