#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-balanced-strings/

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
        d = {}
        for i in s:
            d[i] = d.get(i, 0)+1
        # print(d)
        flag = 1
        for i in d:
            if d[i] == 1:
                print(-1)
                flag = 0
                break
        if flag == 0:
            continue
        flag = 0
        for i in d:
            if d[i] % 2 == 0:
                continue
            else:
                flag = 1
                x = d[i]
                break
        if flag == 1:
            '''flag = 0
            for i in d:
                if d[i] == x:
                    continue
                else:
                    print(-1)
                    flag = 1
                    break
            if flag == 1:
                continue
            else:
                print(x)'''
            print(-1)
        else:
            print(1)


if __name__ == "__main__":
    main()
