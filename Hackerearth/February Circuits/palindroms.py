#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <22/Feb/2019 09:26:54 PM>


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


def insert(source_str, insert_str, pos):
    return source_str[:pos]+insert_str+source_str[pos:]


def ispalindrome(a):
    n = size[a]
    m = n//2
    i = 0
    k = i
    j = 1
    en = end[a]
    while(i < m):
        if arr[a][k] != arr[en][-j]:
            return False
        j += 1
        i += 1
        k += 1

        if (k == len(arr[a])):
            k = 0
            a = next[a]

        if j == len(arr[en])+1:
            j = 1
            en = prev[en]
    if (i == m):
        return True


def main():
    global n, arr, next, size, end, prev
    n, q = get_ints()
    arr = [0]*(n+1)
    next = [i for i in range(n+1)]
    end = [i for i in range(n+1)]
    prev = [i for i in range(n+1)]
    pal = [False]*(n+1)
    size = [0]*(n+1)

    for i in range(1, n+1):
        arr[i] = input().strip()
        size[i] = len(arr[i])
        pal[i] = ispalindrome(i)

    p = 0
    for tc in range(q):
        inp = list(input().split())
        if inp[0] == '1':
            a = int(inp[1]) ^ p
            b = int(inp[2]) ^ p

            _p = p

            if (pal[a] == True):
                p -= 1
                pal[a] = False
            if pal[b] == True:
                p -= 1
                pal[b] = False

            next[end[a]] = b
            prev[b] = end[a]
            end[a] = b
            size[a] += size[b]
            #print(a, end[a])
            if (ispalindrome(a) == True):
                p += 1
                pal[a] = True
        else:
            a = int(inp[1]) ^ p
            b = int(inp[2]) ^ p

            if pal[a] == True:
                p -= 1
                pal[a] = False

            if b == size[a]+1:
                arr[end[a]] += inp[3]
                size[a] += 1

                if ispalindrome(a) == True:
                    p += 1
            else:

                cnt = len(arr[a])
                while(cnt < b):
                    a = next[a]
                    cnt += len(arr[a])

                cnt -= len(arr[a])
                x = b-cnt
                arr[next[a]] = insert(arr[next[a]], inp[3], x-1)
                size[a] += 1
                if ispalindrome(a) == True:
                    p += 1
                    pal[a] = True

        if tc == 0:
            p = 0
            for i in range(1, n+1):
                if pal[i] == True:
                    p += 1
        print(p)
        print(pal)

        i = 0


if __name__ == "__main__":
    main()
