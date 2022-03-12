#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/1051/C
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
    n = int(input())
    arr = get_array()
    d = {}
    for i in arr:
        d[i] = d.get(i, 0)+1
    count = 0
    check = 0
    for i in d:
        if d[i] == 1:
            count += 1
        if d[i] > 2:
            check = 1

    if count % 2 == 0:
        ans = ['A']*n
        flag = 0
        for i in range(n):
            if d[arr[i]] == 1:
                if flag == 1:
                    ans[i] = 'B'
                flag = 1-flag
        print('YES')
        print(*ans, sep='')
        return

    if count % 2 == 1 and check == 0:
        print('NO')
        return

    flag = 0
    check = 0
    ans = ['A']*n
    for i in range(n):
        if d[arr[i]] == 1:
            if flag == 1:
                ans[i] = 'B'
            flag = 1-flag
        if check == 0 and d[arr[i]] > 2:
            check = 1
            ans[i] = 'B'
    print('YES')
    print(*ans, sep='')


if __name__ == "__main__":
    main()
