#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <14/Apr/2019 12:38:30 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()

# ///==========MAIN=============///


def main():
    for tc in range(int(input())):
        n = int(input())
        inp = input().split()
        s = inp[0]
        x = inp[1]
        d = []
        for i in range(n):
            if s[i] == x:
                d.append(i)

        if (len(d)) == 0:
            print(0)
            continue
        p = n - d[0]
        q = d[0]
        ans = p * q
        ans += (n - d[0])
        for i in range(1, len(d)):
            if (d[i] == 1 + d[i - 1]):
                ans += (n - d[i])
                continue
            p = d[i] - d[i - 1] - 1
            q = n - d[i]
            ans += p * q
            ans += (n - d[i])
            #print(p, q, ans)
        print(ans)


if __name__ == "__main__":
    main()
