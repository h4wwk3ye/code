#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/676/C
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def solve(c, s, k):
    global ans
    r = 0
    balance = 0
    for i in range(len(s)):
        while (r < len(s) and (s[r] == c or balance < k)):
            if s[r] != c:
                balance += 1
            r += 1
        ans = max(ans, r-i)
        if s[i] != c:
            balance -= 1
    return


def main():
    n, k = get_ints()
    s = input().strip()
    solve('a', s, k)
    solve('b', s, k)
    print(ans)


if __name__ == "__main__":
    global ans
    ans = 0
    main()
