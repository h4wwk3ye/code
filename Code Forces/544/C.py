#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <07/Mar/2019 10:43:48 PM>


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
    n, k = get_ints()
    arr = get_array()
    ans = 0
    while k > 0:
        print(k, arr, ans)
        d = {}
        for p in range(n):
            i = arr[p]
            if i != -1:
                if i not in d:
                    d[i] = 0
                d[i] += 1
                #arr[p] = -1
        mx = 0
        curr = 0
        for i in d:
            curr = d[i]
            mx = max(mx, curr)
            for j in range(i+1, i+6):
                if j in d:
                    curr += d[j]
                    mx = max(mx, curr)
        ans += mx
        k -= 1
        print(d)

    print(ans)


if __name__ == "__main__":
    main()
