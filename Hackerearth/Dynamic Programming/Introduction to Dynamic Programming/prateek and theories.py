#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/prateek-and-theories-3/
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
        start = [0]*n
        end = [0]*n
        for i in range(n):
            start[i], end[i] = get_ints()
        start.sort()
        end.sort()
        count = 0
        mx = 0
        i, j = 0, 0
        while i < n and j < n:
            if start[i] < end[j]:
                count += 1
                mx = max(count, mx)
                i += 1
            else:
                count -= 1
                j += 1
        print(mx)


if __name__ == "__main__":
    main()
