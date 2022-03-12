#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

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
    for tc in range(int(input())):
        n = int(input())
        arr = get_array()
        prefix_sum = [0]*(n+1)
        for i in range(1, n+1):
            prefix_sum[i] = arr[i-1]+prefix_sum[i-1]
        # print(prefix_sum)
        flag = 0
        for i in range(1, n):
            if prefix_sum[i] == prefix_sum[-1]/2:
                print(0)
                flag = 1
                break
        if flag == 1:
            continue
        mini = inf
        i = 1
        while prefix_sum[i] < prefix_sum[-1]/2:
            #print(i, prefix_sum[i])
            mini = min(prefix_sum[-1]-prefix_sum[i]-prefix_sum[i], mini)
            i += 1
        print(mini) if mini != inf else print(-1)


if __name__ == "__main__":
    main()
