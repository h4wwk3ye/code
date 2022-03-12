#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <14/Apr/2019 10:29:28 AM>


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
        r, g = get_ints()
        if g == 0 and r == 0:
            print(0)
            continue
        if g == 0:
            print(1)
            continue
        if r == 0:
            print(0)
            continue
        prob = r / (r + g)
        g -= 1
        while g > 0:
            prob *= (g / (r + g))
            g -= 1
            if g == 0:
                break
            prob *= (g / (r + g))
            g -= 1
        # print('{0:.6f}'.format(prob))
        print(prob)


if __name__ == "__main__":
    main()
