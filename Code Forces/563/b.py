#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <03/Jun/2019 08:20:25 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    n = int(input())
    arr = get_array()
    even, odd = [], []
    for i in range(n):
        if arr[i] % 2 == 0:
            even.append(i)
        else:
            odd.append(i)
    if len(even) == 0 or len(odd) == 0:
        print(*arr)
        return
    print(*sorted(arr))


if __name__ == "__main__":
    main()
