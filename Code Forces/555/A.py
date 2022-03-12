#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <26/Apr/2019 08:12:30 PM>


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
    n = (input())
    d = {}
    while True:
        if n in d:
            break
        d[n] = 1
        #p = n.join()
        # print(type(n))
        x = list(str(int(n) + 1))
        while x[-1] == '0':
            x.pop()
        # print(n)
        n = ''.join(x)
    # print(d)
    print(len(d))


if __name__ == "__main__":
    main()
