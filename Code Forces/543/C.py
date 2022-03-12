#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <03/Mar/2019 10:52:44 PM>


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
    n, k = get_ints()
    arr = get_array()
    curr = {}
    index = 0
    time = 0
    c = 1
    completed = {}
    ans = 0
    while True:
        #print(time, curr, index)
        if (index != n):
            while (len(curr) != k):
                curr[index] = arr[index]  # +time
                #print(curr, index, time)
                index += 1
        mn = inf
        for i in curr:
            if curr[i] != -1:
                mn = min(mn, curr[i])
        for i, v in list(curr.items()):
            if mn == curr[i]:
                completed[curr[i]] = c
                del curr[i]
                c += 1
        print(curr)
        for j in curr:
            for i in range(1, 101):
                print(i, curr[j], time-j, (c//n)*100)
                if time-curr[j] == (c//n)*100:
                    ans += 1
        time += mn
        if len(curr) == 0:
            break
    flag = 0
    print(ans)
    print(completed)


if __name__ == "__main__":
    main()
