#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <12/May/2019 08:17:52 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    n = int(input())
    s = input()
    x = 0
    ans = 0
    for i in range(n):
        if s[i] == '+':
            x = i
            break
    for i in range(x, n):
        if s[i] == '+':
            ans += 1
        else:
            ans -= 1
    print(ans if ans >= 0 else 0)


if __name__ == "__main__":
    main()
