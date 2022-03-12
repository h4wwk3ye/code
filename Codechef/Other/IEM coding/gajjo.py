#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 09/Nov/19 08:05:54 PM


import sys


def main():
    from collections import Counter

    for tc in range(int(input())):
        s, r = input().split()
        d1 = Counter(s)
        d2 = Counter(r)
        ans = ""
        for i in s:
            if i not in d2:
                ans += i
        for i in r:
            if i not in d1:
                ans += i
        if ans == "":
            print(-1)
            continue
        print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
