#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <27/May/2019 11:43:15 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


ans = float('inf')


def main():
    n, m = get_ints()
    arr = get_array()
    low, high = 0, m - 1
    while (low < high):
        mid = (low + high + 1) // 2
        curr = 0
        for i in range(n):
            if (mid >= arr[i]):
                curr = max(curr, mid - arr[i])
            else:
                curr = max(curr, m - 1 - mid + arr[i])
        ans = min(ans, curr)
    print(ans)


if __name__ == "__main__":
    main()
