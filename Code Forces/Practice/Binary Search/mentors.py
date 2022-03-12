#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <11/Mar/2019 11:19:27 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n, k = get_ints()
    arr = get_array()
    ans = [0 for i in range(n)]
    for i in range(k):
        u, v = get_ints()
        u -= 1
        v -= 1
        if arr[u] > arr[v]:
            ans[u] -= 1
        elif arr[v] > arr[u]:
            ans[v] -= 1

    arr = list(enumerate(arr))
    from operator import itemgetter
    arr.sort(key=itemgetter(1))
    count = {}
    for i in range(n):
        ans[arr[i][0]] += i
        if arr[i][1] in count:
            ans[arr[i][0]] -= count[arr[i][1]]
            count[arr[i][1]] += 1
        else:
            count[arr[i][1]] = 1

    for i in range(n):
        if ans[i] < 0:
            ans[i] = 0
    print(*ans)


if __name__ == "__main__":
    main()
