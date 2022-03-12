#!/usr/bin/env python3
# coding: utf-8
#Last Modified: 06/Mar/20 09:02:51 PM


import sys


def main():
    mod =10**9+7
    vowels = {'a', 'e', 'i', 'o', 'u'}
    for tc in range(int(input())):
        s = input()
        ans = ''
        for i in s:
            if i in vowels:
                ans += '1'
            else:
                ans += '0'
        ans = int(ans, 2)
        ans %= mod
        print(ans)
        


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
