#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <10/Jan/2019 09:22:51 AM>


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
    n, k = get_ints()
    arr = get_array()
    from collections import Counter
    d = Counter(arr)
    for i in d:
        if d[i] > k:
            print('NO')
            return
    # print(d)
    from collections import defaultdict
    d = defaultdict(list)
    for i in range(n):
        d[arr[i]].append(i)
    # print(d)
    x = 1
    for i in d:
        if x > k:
            x = 1
        # print(i)
        for j in d[i]:
            if x > k:
                x = 1
            arr[j] = x
            x += 1
    print('YES')
    print(*arr)


if __name__ == "__main__":
    main()
