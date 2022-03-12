#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <26/Jan/2019 11:45:57 PM>


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
    n = int(input())
    arr = [0] * n
    mx = 1
    for i in range(n):
        arr[i] = input().strip()
    i = 1
    count = 1
    while i < n:
        if arr[i] == arr[0]:
            mx += 1
        else:
            break
        i += 1
    if mx == 1:
        print(1)
        return
    if mx == n:
        print(n)
        return
    while i < n - 1:
        #print(arr[i], arr[i + 1])
        if arr[i] == arr[i + 1]:
            count += 1
        else:
            mx = min(mx, count)
            count = 1
        i += 1
    mx = min(mx, count)
    if mx == 1:
        print(1)
        return
    i = 0
    step = mx
    while i < n:
        start = arr[i]
        j = i + 1
        while j < n and j < i + mx:
            #print(start, arr[j])
            if arr[j] != start:
                print(1)
                return
            j += 1
        i = j
    print(mx)


if __name__ == "__main__":
    main()
