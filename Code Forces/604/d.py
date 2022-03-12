#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 06/Dec/19 10:46:29 AM


import sys


def main():
    a, b, c, d = get_ints()

    if a + b + c + d == 1:
        print("YES")
        if a == 1:
            print(0)
            return
        if b == 1:
            print(1)
            return
        if c == 1:
            print(2)
            return
        if d == 1:
            print(3)
            return

    def quit():
        print("NO")
        exit(0)

    ans = []
    if b > a:
        ans.append(1)
        b -= 1

    while a > 0 and b > 0:
        ans.append(0)
        ans.append(1)
        a -= 1
        b -= 1
    # print(a, b, c, d)
    if a > 0 and c != 0 and d != 0:
        quit()

    while b > 0 and c > 0:
        ans.append(2)
        ans.append(1)
        c -= 1
        b -= 1
    # print(a, b, c, d)
    if b > 0:
        quit()
    if c == 0 and d != 0:
        quit()

    while c > 0 and d > 0:
        ans.append(2)
        ans.append(3)
        c -= 1
        d -= 1
    if c:
        ans.append(2)
        c -= 1

    if c == 1 and ans[0] == 1:
        ans.insert(0, 2)
        c -= 1
    if d == 1 and ans[0] == 2:
        ans.insert(0, 3)
        d -= 1

    if a == 1 and b == 0 and c == 0 and d == 0:
        a -= 1
        ans.append(0)

    for i in range(1, len(ans)):
        if abs(ans[i - 1] - ans[i]) != 1:
            quit()

    if a or b or c or d:
        quit()
    print("YES")
    print(*ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
