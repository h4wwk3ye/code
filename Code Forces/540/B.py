#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <19/Feb/2019 11:39:02 PM>


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
    arr = get_array()
    #prefix = [0] * (n + 1)
    odd = [0] * (n + 1)
    even = [0] * (n + 1)
    for i in range(1, n + 1):
        #prefix[i] += (prefix[i - 1] + arr[i - 1])
        if i % 2 == 1:
            even[i] = even[i - 1]
            if i == 1:
                odd[i] = arr[i - 1]
            else:
                odd[i] += (odd[i - 2] + arr[i - 1])
        else:
            even[i] += (even[i - 2] + arr[i - 1])
            odd[i] = odd[i - 1]
    # print(prefix)
    # print(odd)
    # print(even)
    ans = 0
    for i in range(1, n + 1):
        x = odd[i - 1] + (even[-1] - even[i])
        y = even[i - 1] + (odd[-1] - odd[i])
        #print(i, x, y)
        if x == y:
            ans += 1
            # print(i)
    print(ans)


if __name__ == "__main__":
    main()
