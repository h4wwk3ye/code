#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Mar/2019 07:39:48 PM>


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
        s = list(input().strip())
        s.sort()
        x = Counter(s)
        if len(x) != len(s):
            print('NO')
            continue
        for i in range(len(s)):
            s[i] = ord(s[i])
        flag = 0
        for i in range(1, len(s)):
            if s[i]-1 != s[i-1]:
                print('NO')
                flag = 1
                break
        if flag == 0:
            print('YES')


if __name__ == "__main__":
    main()
