#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Mar/2019 08:00:25 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    arr.sort()
    from collections import Counter
    x = Counter(arr)
    a = []
    b = []
    for i in x:
        if x[i] == 1:
            a.append(i)
            continue
        elif x[i] == 2:
            a.append(i)
            b.append(i)
        elif x[i] > 2:
            print('NO')
            return
    print('YES')
    print(len(a))
    a.sort()
    print(*a)
    print(len(b))
    b.sort(reverse=True)
    print(*b)


if __name__ == "__main__":
    main()
