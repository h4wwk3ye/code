#	!/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Dec/2018 02:30:05 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/873/B
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(20000)

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    s = input().strip()
    d = {0: -1}
    mx = 0
    count = 0
    for i in range(n):
        if s[i] == '1':
            count += 1
        else:
            count -= 1
        if count in d:
            mx = max(mx, i - d[count])
        else:
            d[count] = i
    print(mx)


if __name__ == "__main__":
    main()
