#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <06/Jun/2019 10:12:26 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


from collections import OrderedDict
import sys
sys.setrecursionlimit(10**6)
#import resource
#resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def solve(i, d):
    '''if (dp[i] != 0):
        return dp[i]'''

    if (i == n):
        flag = True
        od = OrderedDict(sorted(d.items()))
        prev = -1
        print(od)
        for k, v in od.items():
            if (od[k] <= prev):
                flag = False
                break
            prev = v
        if flag == True:
            return len(d)
        else:
            return 0

    x = solve(i + 1, d)
    if arr[i] not in d:
        d[arr[i]] = 0
    d[arr[i]] += 1
    y = solve(i + 1, d)
    #dp[i] = max(x, y)
    return max(x, y)


def main():
    global n, arr, dp
    n = int(input())
    dp = [0] * (n + 1)
    arr = get_array()
    d = {}
    print(solve(0, d))


if __name__ == "__main__":
    main()
