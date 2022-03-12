#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/550/C
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
    n = input().strip()
    l = len(n)
    for i in range(l):
        if int(n[i]) % 8 == 0:
            print('YES')
            print(n[i])
            return
        for j in range(i+1, l):
            if int(n[i]+n[j]) % 8 == 0:
                print('YES')
                print(n[i]+n[j])
                return
            for k in range(j+1, l):
                if int(n[i]+n[j]+n[k]) % 8 == 0:
                    print('YES')
                    print(n[i]+n[j]+n[k])
                    return
    print('NO')


if __name__ == "__main__":
    main()
