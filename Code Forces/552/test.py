#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <17/Apr/2019 07:45:49 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    arr.sort()
    if len(arr) == 2:
        if (arr[1] - arr[0]) % 2 == 0:
            print((arr[1] - arr[0]) // 2)
            return
        else:
            print(arr[1] - arr[0])
    ans = float("inf")
    for i in range(n):
        x = arr[i]
        mn = {}
        for j in range(n):
            if i == j:
                continue
            if arr[i] == arr[j]:
                continue
            curr = abs(arr[j] - arr[i])
            mn[curr] = 1
        if len(mn) == 0:
            print(0)
            return
        if len(mn) == 1:
            for l in mn:
                ans = min(ans, l)
    if ans == float('inf'):
        print(-1)
    else:
        print(ans)


if __name__ == "__main__":
    main()
