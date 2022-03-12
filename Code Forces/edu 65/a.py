#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <16/May/2019 06:40:56 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    for tc in range(int(input())):
        n = int(input())
        s = list(input())
        j = 0
        for i in range(n):
            if s[i] != '8':
                j += 1
            else:
                break
        s = s[j:]
        # print(s)
        if (len(s) < 11):
            print('NO')
        else:
            print('YES')


if __name__ == "__main__":
    main()
