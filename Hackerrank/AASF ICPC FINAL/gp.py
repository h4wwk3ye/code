#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <30/Mar/2019 08:59:36 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()

    if n == 1:
        print(0)
        return

    i = 0
    curr, mx = 0, 0
    r = 1

    op = []
    d = {}

    while i < n-1:
        if arr[i+1]/arr[i] == r:
            curr += 1
            mx = max(mx, curr)
            op.append(arr[i])

        else:
            curr = 1
            mx = max(mx, curr)
            op.append(i)
            r = arr[i+1]/arr[i]
            op = tuple(op)
            if len(op) > 1:
                if op not in d:
                    d[op] = 0
                d[op] += 1
                op = []
        i += 1
    print(d)


if __name__ == "__main__":
    main()
