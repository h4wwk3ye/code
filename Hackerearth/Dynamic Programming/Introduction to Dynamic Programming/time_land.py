#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/once-upon-a-time-in-time-land/
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


'''def solve(i):
    if i >= n:
        return 0
    return max(solve(i+1), solve(i+1+k)+arr[i])'''


def solve():
    dp[0] = arr[0]
    for i in range(1, k+1):
        dp[i] = max(dp[i-1], arr[i])
    for i in range(k+1, n):
        dp[i] = max(dp[i-1-k]+arr[i], dp[i-1], arr[i])


if __name__ == "__main__":
    for tc in range(int(input())):
        n, k = get_ints()
        arr = get_array()
        dp = [0]*n
        solve()
        print(dp[-1]) if dp[-1] > 0 else print(0)
