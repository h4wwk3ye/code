#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <27/May/2019 11:29:25 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    n, m = get_ints()
    arr = [0] * m
    for i in range(m):
        a, b = get_ints()
        arr[i] = (a, b)
    x = arr[0][0]
    flag = True
    ind = 0
    for i in range(m):
        if x not in arr[i]:
            flag = False
            ind = i
            y = arr[i][0]
            break
    if flag:
        print('YES')
        return
    flag = True
    for i in range(ind, m):
        if y not in arr[i] and x not in arr[i]:
            flag = False
            break
    if flag:
        print('YES')
        return
    y = arr[ind][1]
    flag = True
    for i in range(ind, m):
        if y not in arr[i] and x not in arr[i]:
            flag = False
            break
    if flag:
        print('YES')
        return
    ####################
    x = arr[0][1]
    flag = True
    ind = 0
    for i in range(m):
        if x not in arr[i]:
            flag = False
            ind = i
            y = arr[i][0]
            break
    if flag:
        print('YES')
        return
    flag = True
    for i in range(ind, m):
        if y not in arr[i] and x not in arr[i]:
            flag = False
            break
    if flag:
        print('YES')
        return
    y = arr[ind][1]
    flag = True
    for i in range(ind, m):
        if y not in arr[i] and x not in arr[i]:
            flag = False
            break
    if flag:
        print('YES')
        return
    print('NO')


if __name__ == "__main__":
    main()
