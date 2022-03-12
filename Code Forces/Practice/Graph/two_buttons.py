#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <03/Mar/2019 05:58:59 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys

mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n, m = get_ints()
    if n == m:
        print(0)
        return
    from collections import deque
    q = deque()
    q.append((n, 1))
    while(q):
        p = q.popleft()
        a = p[0]-1
        b = p[0]*2
        if (a == m or b == m):
            print(p[1])
            return
        q.append((a, p[1]+1))
        if (p[0] < m):
            q.append((b, p[1]+1))


if __name__ == "__main__":
    main()
