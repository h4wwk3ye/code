#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <26/Jan/2019 11:28:16 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

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
        n = int(input())
        s = input().strip()
        flag = 0
        i = 1
        while i < n:
            #print(s[:i], s[i:])
            if int(s[:i]) < int(s[i:]):
                print('YES')
                print(2)
                print(s[:i], s[i:])
                flag = 1
                break
            i += 1
        if flag == 1:
            continue
        print('NO')


if __name__ == "__main__":
    main()
