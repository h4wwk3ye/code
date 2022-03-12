#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 30/Oct/19 07:50:52 PM


import sys


def main():
    for tc in range(int(input())):
        n = list(input())
        ans = ""
        l = len(n)
        if l == 1:
            print(*n)
            continue
        for i in range(l - 1):
            ans += str(int(n[i]) ^ int(n[i + 1]))
        ans += str(int(n[0]) ^ int(n[-1]))
        print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
