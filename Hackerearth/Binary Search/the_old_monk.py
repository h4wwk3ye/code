#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Mar/2019 12:29:06 PM>


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
    for tc in range(int(input())):
        n = int(input())
        A = get_array()
        B = get_array()
        mx = 0
        flag = 0
        for i in range(n):
            x = A[i]
            low = 0
            high = n-1
            while low < high:
                #print(low, high)
                mid = (low+high+1)//2
                if B[mid] >= x:
                    flag = 1
                    low = mid
                else:
                    high = mid-1
            if flag == 1:
                mx = max(mx, low-i)
        print(mx)


if __name__ == "__main__":
    main()
