#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 06/Dec/19 09:14:09 AM


import sys


def main():
    for tc in range(int(input())):
        s = list(input())
        for i in range(len(s)):
            if s[i] == "?":
                if i > 0 and i < len(s) - 1:
                    if (s[i - 1] == "a" or s[i - 1] == "b") and (
                        s[i + 1] == "a" or s[i + 1] == "b"
                    ):
                        s[i] = "c"
                    elif (s[i - 1] == "a" or s[i - 1] == "c") and (
                        s[i + 1] == "a" or s[i + 1] == "c"
                    ):
                        s[i] = "b"
                    elif (s[i - 1] == "c" or s[i - 1] == "b") and (
                        s[i + 1] == "c" or s[i + 1] == "b"
                    ):
                        s[i] = "a"
                    else:
                        if s[i - 1] == "a":
                            s[i] = "b"
                        elif s[i - 1] == "b":
                            s[i] = "c"
                        elif s[i - 1] == "c":
                            s[i] = "a"
                elif i == 0 and i < len(s) - 1:
                    if s[i + 1] == "a":
                        s[i] = "b"
                    elif s[i + 1] == "b":
                        s[i] = "c"
                    elif s[i + 1] == "c":
                        s[i] = "a"
                    else:
                        s[i] = "a"
            if i + 1 < len(s):
                if s[i] == s[i + 1]:
                    s = "-1"
                    break
        if s[-1] == "?":
            if len(s) == 1:
                s[-1] = "a"
            elif s[-2] == "a":
                s[-1] = "b"
            elif s[-2] == "b":
                s[-1] = "c"
            elif s[-2] == "c":
                s[-1] = "a"

        print(*s, sep="")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
