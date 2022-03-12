#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <04/Apr/2019 09:33:12 PM>


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
    arr = [0]*n
    for i in range(n):
        arr[i] = int(input())

    arr.sort()

    from bisect import bisect_left
    ans = 0
    for tc in range(int(input())):
        k = int(input())
        i = bisect_left(arr, k)
        i -= 1
        ans += (n-i-1)
        #print(i, 'i')
        if arr[i] != k-1:
            # print(ans)
            continue

        j = bisect_left(arr, k-1)
        j -= 1
        #print(i, j)

        ans += min(i-j, j+1)
        # print(ans)
    print(ans)


if __name__ == "__main__":
    main()
