#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <26/May/2019 09:11:38 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    n, a, x, b, y = get_ints()
    daniel = [-1] * (n + 1)
    if x >= a:
        t = 0
        for i in range(a, x + 1):
            daniel[i] = t
            t += 1
    else:
        t = 0
        for i in range(a, n + 1):
            daniel[i] = t
            t += 1
        for i in range(1, x + 1):
            daniel[i] = t
            t += 1

    vlad = [-1] * (n + 1)
    if y <= b:
        t = 0
        for i in range(b, y - 1, -1):
            vlad[i] = t
            t += 1
    else:
        t = 0
        for i in range(b, 0, -1):
            vlad[i] = t
            t += 1
        for i in range(n, y - 1, -1):
            vlad[i] = t
            t += 1
    ans = 'NO'
    for i in range(1, n + 1):
        if daniel[i] == vlad[i] and daniel[i] != -1:
            ans = 'YES'
            break
    # print(vlad)
    # print(daniel)
    print(ans)


if __name__ == "__main__":
    main()
