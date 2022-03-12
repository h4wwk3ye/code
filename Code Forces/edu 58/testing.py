#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <11/Jan/2019 11:29:52 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

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


def test(l, r, d):
    if d < l:
        return d
    q = r // d
    min = q * d
    return min + d


def main(l, r, d):
    from math import floor
    #l, r, d = get_ints()
    if d < l:
        return(d)
    elif d >= l and d <= r:
        return((d * floor(r / d)) + d)
    else:
        return(d)


if __name__ == "__main__":
    from random import randint
    #print(test(206530, 857939, 637164))
    while True:
        d = randint(1, 1000000)
        l = randint(1, 1000000)
        r = randint(l, 1000000)
        #print(l, r, d)
        if test(l, r, d) != main(l, r, d):
            print(l, r, d)
            break
