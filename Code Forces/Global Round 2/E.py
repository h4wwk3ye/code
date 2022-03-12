#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <06/Apr/2019 07:01:51 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    ans = 0
    curr = 0
    for i in range(n-1, -1, -1):
        if arr[i] < 2:
            continue
        if arr[i] >= 3:
            ans += (arr[i]//3)
            x = arr[i]//3
            arr[i] -= 3*x
        x = arr[i]//2
        y = 0
        while y != x:
            #print(i, curr, ans, x, y)
            if curr == i:
                break
            p = arr[curr]
            arr[curr] -= (x-y)
            y += min(p, x-y)
            if (arr[curr] <= 0):
                curr += 1

            # print(arr)
        ans += x
        # print(i)
        # print(arr)
    print(ans)


if __name__ == "__main__":
    main()
