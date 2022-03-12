#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <26/Apr/2019 10:10:15 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()

# ///==========MAIN=============///


inf = float("inf")


def main():
    n = int(input())
    a = get_array()
    d = get_array()
    # print(a)
    # print(b)
    #from collections import Counter
    import collections
    b = {}
    for i in d:
        b[i] = b.get(i, 0) + 1
    #b = Counter(b)
    # print(b)
    b = collections.OrderedDict(sorted(b.items()))
    from bisect import bisect_left
    #mini = min(b)
    # print(b)
    for i in range(n):
        # print(i)
        x = n - a[i]
        # print(x)
        x %= n
        '''while True:
            #x = n - a[i]
            if x in b and b[x] != 0:
                #print(i, a[i], x, b[x])
                a[i] = (a[i] + x) % n
                # print(a[i])
                b[x] -= 1
                if b[x] == 0:
            del b[x]
                break
            x += 1
            x %= n'''
        k = list(b.keys())
        ind = bisect_left(k, x)
        if ind == len(k):
            ind = 0
        ind = k[ind]
        #print(ind, k, i, b[ind])
        a[i] = (a[i] + ind) % n
        b[ind] -= 1
        if b[ind] == 0:
            del b[ind]

        # for i in range()

    print(*a)


if __name__ == "__main__":
    main()
