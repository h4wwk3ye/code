# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

import sys
from collections import deque
inf = float("inf")
mod = 1000000007


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()


def get_ints():
    return map(int, sys.stdin.readline().split())

# ///==========MAIN=============///


def main():
    Q, K = get_ints()
    que_del = deque()
    que_col = deque()
    ans = 0
    dct = dict()
    flag = 0
    for i in range(Q):
        inp = input().split()
        c = int(inp[1]) ^ ans
        if inp[0] == '1':
            d = int(inp[2])
            que_del.appendleft(d)
            que_col.appendleft(c)
            flag = 1
        elif inp[0] == '2':
            d = int(inp[2])
            que_del.append(d)
            que_col.append(c)
            flag = 1
        else:
            if c in dct and flag == 0:
                print(dct[c], sep=' ', end='\n', file=sys.stdout, flush=False)
            else:
                left, right = c-K, c+K
                max_ending_here = 0
                ans = 0
                for i in range(len(que_col)):
                    color = que_col[i]
                    if que_col[i] >= left and que_col[i] <= right:
                        max_ending_here += que_del[i]
                        if max_ending_here < 0:
                            max_ending_here = 0
                        elif ans < max_ending_here:
                            ans = max_ending_here
                dct[c] = ans
                flag = 0
                print(ans, sep=' ', end='\n', file=sys.stdout, flush=False)


if __name__ == '__main__':
    main()
