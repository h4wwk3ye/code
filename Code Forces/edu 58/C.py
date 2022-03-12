#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <11/Jan/2019 10:18:42 PM>


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
    from operator import itemgetter
    for tc in range(int(input())):
        n = int(input())
        arr = [0] * n
        for i in range(n):
            l, r = get_ints()
            arr[i] = [l, r]
        arr = list(enumerate(arr))
        arr.sort(key=itemgetter(1))
        r_max = arr[0][1][1]
        i = 0
        while i < n and arr[i][1][0] <= r_max:
            r_max = max(r_max, arr[i][1][1])
            i += 1
        if i == n:
            print(-1)
            continue
        ans = [2] * n
        for point in arr:
            ans[point[0]] = 1
            i -= 1
            if i == 0:
                break
        print(*ans)


if __name__ == "__main__":
    main()
