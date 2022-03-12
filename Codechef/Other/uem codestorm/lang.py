#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 02/Nov/19 09:00:28 PM


import sys


def main():
    s = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
    t = "our language is impossible to understand"
    d = {}
    for i in range(len(s)):
        d[s[i]] = t[i]
    s = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
    t = "there are twenty six factorial possibilities"
    for i in range(len(s)):
        d[s[i]] = t[i]
    s = "de kr kd eoya kw aej tysr re ujdr lkgc jv"
    t = "so it is okay if you want to just give up"
    for i in range(len(s)):
        d[s[i]] = t[i]
    d["y"] = "a"
    d["e"] = "o"
    d["q"] = "z"
    a = ""
    for i in range(26):
        if (chr(i + 97)) not in d:
            a = chr(i + 97)
    x = {}

    for i in d:
        x[d[i]] = 1

    b = ""
    for i in range(26):
        if (chr(i + 97)) not in x:
            b = chr(i + 97)

    d[a] = b
    for tc in range(int(input())):
        s = input()
        ans = ""
        for i in s:
            ans += d[i]
        print("Case #", tc + 1, ": ", sep="", end="")
        print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
