#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <30/Mar/2019 09:47:28 AM>


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
    a = ['2', '4', '8']
    from itertools import combinations_with_replacement
    # arr=[]
    '''for i in range(1, 19):
        x = list(combinations_with_replacement(a, i))
        # print(*x)
        arr.append(len(x))'''
    arr = [3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190]
    prefix = [3]
    for i in range(1, len(arr)):
        prefix.append(prefix[i-1]+arr[i])
    # print(arr)
    # print(prefix)
    p = input().strip()
    l = len(p)
    n = int(p)

    if (n < 2):
        print(0)
        return
    if n >= 2 and n < 4:
        print(1)
        return
    if n >= 4 and n < 8:
        print(2)
        return
    if n >= 8 and n < 22:
        print(3)
        return

    ans = prefix[l-2]

    x = list(combinations_with_replacement(a, l))
    x.sort()
    print(x)
    for i in x:
        m = int((''.join(u for u in i)))
        if m <= n:
            ans += 1
        else:
            break

    print(ans)


if __name__ == "__main__":
    main()
