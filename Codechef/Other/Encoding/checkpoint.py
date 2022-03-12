#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 30/Oct/19 07:45:20 PM


import sys


def main():
    mod = 10 ** 9 + 7
    for tc in range(int(input())):
        N, k = get_ints()
        d = k
        l = N // k * k
        a = 0
        n = (l - a) // d + 1
        s = ((a + l) * n) // 2
        s %= mod
        s *= 2
        s %= mod
        s += N
        s %= mod
        print(s)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
