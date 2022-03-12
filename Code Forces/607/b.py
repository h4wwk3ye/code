#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 15/Dec/19 12:23:54 PM


import sys


def main():
    for tc in range(int(input())):
        s, c = input().split()
        s = list(s)
        flag = 0
        for i in range(min(len(s), len(c))):
            if s[i] < c[i]:
                break
            if s[i] == c[i]:
                for j in range(i + 1, len(s)):
                    if s[j] < c[i]:
                        s[j], s[i] = s[i], s[j]
                        flag = 1
                        break
                continue

            x = c[i]

            mn = i

            for j in range(i + 1, len(s)):
                if s[j] < x and s[j] <= s[mn]:
                    mn = j

            if mn != i:
                flag = 1
                s[mn], s[i] = s[i], s[mn]

            if flag == 1:
                break
            for j in range(len(s) - 1, i, -1):
                if s[j] == x:
                    if j >= len(c):
                        s[j], s[i] = s[i], s[j]
                        flag = 1
                        break
                    else:
                        if c[j] <= s[i]:
                            continue
                        else:
                            s[j], s[i] = s[i], s[j]
                            flag = 1
                            break

            if flag == 1:
                break

            for j in range(len(s) - 1, i, -1):
                if s[j] == x:
                    s[j], s[i] = s[i], s[j]
                    flag = 1
                    break

            if flag == 1:
                break

        flag = 0
        for i in range(min(len(s), len(c))):
            if s[i] < c[i]:
                flag = 1
                break
            if s[i] > c[i]:
                flag = 2
                break
        if flag == 0 and len(s) < len(c):
            flag = 1

        if flag == 0:
            print("---")
            continue
        if flag == 2:
            print("---")
            continue
        print(*s, sep="")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
