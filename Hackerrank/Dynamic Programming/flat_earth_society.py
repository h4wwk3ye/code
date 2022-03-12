#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/flat-earth-society/
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(10000)
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


'''
def solve(arr, r, i, dp):
    if i >= len(arr):
        return 0
    if dp[i] is not None:
        return dp[i]
    dp[i] = max(solve(arr, r, i+1, dp), arr[i]+solve(arr, r, i+r+1, dp))
    return dp[i]


def sol_an(arr, l, i, dp):
    if i < 0:
        return 0
    if dp[i] is not None:
        return dp[i]
    dp[i] = max(sol_an(arr, l, i-1, dp), arr[i]+sol_an(arr, l, i-1-l, dp))
    return dp[i]
'''


def main():
    for tc in range(int(input())):
        n, l, r = get_ints()
        arr = get_array()
        l = min(l, r)
        aux = [0]*100001
        dp = [0]*100001
        for i in range(n):
            aux[arr[i]] += 1
        for i in range(1, 100001):
            if i-l <= 0:
                dp[i] = max(dp[i-1], i*aux[i])
            else:
                dp[i] = max(dp[i-1], aux[i]*i+dp[i-1-l])
        print(dp[-1])


if __name__ == "__main__":
    main()
