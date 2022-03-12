#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <06/Feb/2019 10:46:20 PM>


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


def main():
    seq = [0, 4, 8, 2, 6]
    for tc in range(int(input())):
        s = input().strip()
        n = len(s)
        d = {}
        flag = 0
        for i in s:
            if i == '0':
                print('YES', 0)
                flag = 1
                break
            elif i == '4':
                d[4] = 1
            elif i == '8':
                d[8] = 1
        if flag == 1:
            continue
        if 4 in d:
            print('YES', 4)
            continue
        if 8 in d:
            print('YES', 8)
            continue

        d = {i: [] for i in range(1, 10)}
        for i in range(n):
            p = int(s[i])
            d[p].append(i)
        # print(d)
        # print(d)
        if len(d[1]) > 0:
            if len(d[2]) > 0:
                x = d[1][0]
                y = d[2][-1]
                if x < y:
                    print('YES', 12)
                    continue
            if len(d[6]) > 0:
                x = d[1][0]
                y = d[6][-1]
                if x < y:
                    print('YES', 16)
                    continue

        if len(d[3]) > 0:
            #print(len(d[3]), 'yes')
            if len(d[2]) > 0:
                x = d[3][0]
                y = d[2][-1]
                if x < y:
                    print('YES', 32)
                    continue
            if len(d[6]) > 0:
                x = d[3][0]
                y = d[6][-1]
                if x < y:
                    print('YES', 36)
                    continue
        if len(d[5]) > 0:
            if len(d[2]) > 0:
                x = d[5][0]
                y = d[2][-1]
                if x < y:
                    print('YES', 52)
                    continue
            if len(d[6]) > 0:
                x = d[5][0]
                y = d[6][-1]
                if x < y:
                    print('YES', 56)
                    continue

        if len(d[7]) > 0:
            if len(d[2]) > 0:
                x = d[7][0]
                y = d[2][-1]
                if x < y:
                    print('YES', 72)
                    continue
            if len(d[6]) > 0:
                x = d[7][0]
                y = d[6][-1]
                if x < y:
                    print('YES', 76)
                    continue

        if len(d[9]) > 0:
            if len(d[2]) > 0:
                x = d[9][0]
                y = d[2][-1]
                if x < y:
                    print('YES', 92)
                    continue
            if len(d[6]) > 0:
                x = d[9][0]
                y = d[6][-1]
                if x < y:
                    print('YES', 96)
                    continue
        # ans.sort()
        #print('YES', ans[0])
        print('NO')


if __name__ == "__main__":
    main()
