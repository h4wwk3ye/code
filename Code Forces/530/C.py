#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <06/Jan/2019 12:02:42 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
#from atexit import register
#from io import StringIO as stream

inf = float("inf")
mod = 1000000007


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    s = input().strip()
    k = int(input())
    count = 0
    ans = ''
    for i in range(len(s)):
        if i + 1 < len(s) and s[i] != '?' and s[i] != '*':
            if s[i + 1] != '?' and s[i + 1] != '*':
                count += 1
                ans += s[i]
    if s[-1] != '?' and s[-1] != '*':
        count += 1
        ans += s[-1]
    if count > k:
        print('Impossible')
        return
    if count == k:
        print(ans)
        return
    ans = ''
    flag = 0
    for i in range(len(s)):
        if i + 1 < len(s) and s[i] != '?' and s[i] != '*':
            if s[i + 1] != '?' and s[i + 1] != '*':
                ans += s[i]
            elif s[i + 1] == '*' and flag == 0:
                ans += (s[i] * (k - count))
                flag = 1
    if s[-1] != '?' and s[-1] != '*':
        ans += s[-1]
    if flag == 1:
        print(ans)
        return
    ans = ''
    flag = 0
    other_count = 0
    for i in range(len(s)):
        if i + 1 < len(s) and s[i] != '?':
            if s[i + 1] != '?':
                ans += s[i]
            elif s[i + 1] == '?' and flag == 0:
                ans += s[i]
                other_count += 1
                if k - count == other_count:
                    flag = 1
    if s[-1] != '?' and s[-1] != '*':
        ans += s[-1]
    if len(ans) != k:
        print('Impossible')
        return
    print(ans)


if __name__ == "__main__":
        # fast_io()
    main()
