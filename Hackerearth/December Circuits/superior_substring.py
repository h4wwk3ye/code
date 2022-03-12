#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/challenge/competitive/december-circuits-18/algorithm/superior-substring-dec-circuits-e51b3c27/
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
    for tc in range(int(input())):
        n = int(input())
        string = input()
        count = {}
        start = {}
        mx = 0
        now = 0
        ans = 0
        for i in range(n):
            x = string[i]
            if x not in count:
                start[x] = i
                count[x] = 0
            count[x] += 1
            if count[x] > mx:
                now = x
                mx = count[x]
            if mx >= (i-start[now])//2:
                #print(i, now)
                ans = i-start[now]
                if mx == ans/2:
                    ans += 1
        #print(start, mx)

        print(ans)


if __name__ == "__main__":
    main()
