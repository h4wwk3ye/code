#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <01/Jan/2019 05:53:30 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
from atexit import register
from io import StringIO as stream

inf = float("inf")
mod = 100000

sys.stdin = open('input.txt', 'r')


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    root, ans = get_ints()
    n = int(input())
    keys = get_array()
    from collections import deque
    queue = deque()
    queue.append(root)
    depth = [-1 for _ in range(100004)]
    depth[root] = 0
    while queue:
        pop = queue.popleft()
        for key in keys:
            prod = (key * pop) % mod
            if depth[prod] == -1:
                queue.append(prod)
                depth[prod] = 1 + depth[pop]
                if prod == ans:
                    print(depth[prod])
                    return
    print(-1)


if __name__ == "__main__":
    # fast_io()
    main()
