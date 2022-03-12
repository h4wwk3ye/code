#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.codechef.com/LTIME67A/problems/AGECAL
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
        days = get_array()
        total = sum(days)
        prefix_days = [0]*n
        prefix_days[0] = days[0]
        for i in range(1, n):
            prefix_days[i] = prefix_days[i-1]+days[i]
        y, m, d = get_ints()
        cy, cm, cd = get_ints()
        years = cy-y-1
        count = 0
        if cm == 1:
            count = cd
        else:
            count = prefix_days[cm-2]
            count += cd
        # print(count)
        leap = 0
        for i in range(y+1, cy):
            if i % 4 == 0:
                leap += 1
        if cy > y:
            if years >= 1:
                count += (total*years)
            # print(count)
            if m == 1:
                count += prefix_days[-1]
            else:
                count += (prefix_days[-1]-prefix_days[m-2])
            count -= (d-1)
            count += leap

        print(count)


if __name__ == "__main__":
    main()
