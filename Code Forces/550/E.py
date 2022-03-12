#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Mar/2019 08:14:57 PM>


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
    t = input().strip()
    a = []
    for i in s:
        x = str(ord(i))
        a.append(x)
    b = []
    for i in t:
        x = str(ord(i))
        b.append(x)
    a = int(''.join(u for u in a))
    b = int(''.join(u for u in b))
    print(a, b)
    if (b-a) % 2 == 0:
        k = 1
    else:
        k = 0
    x = str(((b+a)//2)+k)

    ans = []

    for i in x:
        ans.append(chr(i))
    print(*ans)


if __name__ == "__main__":
    main()
