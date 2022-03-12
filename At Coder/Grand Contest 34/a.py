#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <02/Jun/2019 05:52:55 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    n, a, b, c, d = get_ints()
    s = list(input())
    s.insert(0, 0)

    if a == c and b == d:
        print('Yes')
        return
    if c < a or d < b:
        print('No')
        return
    i, j = a, b
    while (i != c or j != d):
        print(i, j)
        if i < c:
            if i + 1 <= c and s[i + 1] == '.' and i + 1 != j:
                i += 1
            elif i + 2 <= d and s[i + 2] == '.' and i + 2 != j:
                i += 2
        if j < d:
            if j + 1 <= d and s[j + 1] == '.' and j + 1 != i:
                j += 1
            elif j + 2 <= d and s[j + 2] == '.' and j + 2 != i:
                j += 2
    print(i, j)
    if i == c and j == d:
        print('Yes')
    else:
        print('No')


if __name__ == "__main__":
    main()
