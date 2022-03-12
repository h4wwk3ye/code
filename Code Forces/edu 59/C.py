#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <26/Jan/2019 10:15:00 PM>


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


import bisect


def main():
    n, k = get_ints()
    arr = get_array()
    s = input().strip()
    if k >= n:
        print(sum(arr))
        return
    # print(sum(arr))
    from collections import Counter
    co = Counter(s)
    if len(co) == 1:
        arr.sort(reverse=True)
        print(sum(arr[:k]))
        return

    i = 0
    ans = 0
    count = 0
    while i < n - 1:
        if s[i] != s[i + 1]:
            count = 0
            i += 1
        else:
            start = i
            while i < n - 1 and s[i] == s[i + 1]:
                count += 1
                i += 1
            end = i
            #print(start, end)
            if end - start < k:
                continue
            else:
                x = sorted(arr[start:end + 1])
                # print(x)
                ans -= sum(x[:count - k + 1])
    ans += sum(arr)
    print(ans)


if __name__ == "__main__":
    main()
