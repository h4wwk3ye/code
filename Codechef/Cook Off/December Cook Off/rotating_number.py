#	!/bin/env python3
#	coding: UTF-8


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
        s = input().strip()
        l = len(s)
        n = int(s) % mod
        q = pow(10, l-1, mod)
        #print('q', q)
        x = 0
        for i in range(l):
            x = (x*(q*10) % mod) % mod  # adding trailing zeroes
            #print('x1', x)
            x = (x+n) % mod  # adding rotated value
            #print('x2', x)
            n = ((n-(int(s[i])*q)+mod) % mod)*10+int(s[i]) % mod  # rotation
            #print('n', n)
        print(x % mod)


if __name__ == "__main__":
    main()
