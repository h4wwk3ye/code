#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <12/Apr/2019 08:26:46 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


sys.stdin = open('inp.txt', 'r')

# ///==========MAIN=============///


def ispal(x):
    i = 0
    j = len(x)-1
    if j == 0:
        return False
    while i < j:
        if x[i] != x[j]:
            return False
        i += 1
        j -= 1
    return True


if __name__ == "__main__":
    s = input()
    n = len(s)
    ans = 0
    for i in range(n):
        for j in range(i, n):
            for k in range(j+1, n):
                for l in range(k, n):

                    if (ispal(s[i:j+1]+s[k:l+1])):
                        # if (ispal(x)):
                        ans += 1
    print(ans)
