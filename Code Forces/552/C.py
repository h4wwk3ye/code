#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <16/Apr/2019 08:46:08 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()

# ///==========MAIN=============///


def main():
    a, b, c = get_ints()
    p = a // 3
    q = b // 2
    r = c // 2
    mn = min(p, q, r)
    ans = mn * 7

    # print(ans)
    a -= (mn * 3)
    b -= (mn * 2)
    c -= (mn * 2)
    curr = 0
    mx = 0
    #print(a, b, c)
    for j in range(7):
        x = a
        y = b
        z = c
        curr = 0
        for p in range(j, j + 7):
            # print(p)
            i = p % 7
            #print(p, i, j)
            if i == 0 or i == 3 or i == 6:
                if x > 0:
                    x -= 1
                    curr += 1
                    mx = max(mx, curr)
                else:
                    break
            elif i == 1 or i == 5:
                if y > 0:
                    y -= 1
                    curr += 1
                    mx = max(mx, curr)
                else:
                    break
            else:
                if z > 0:
                    z -= 1
                    curr += 1
                    mx = max(mx, curr)
                else:
                    break
    # print(mx)
    print(ans + mx)


if __name__ == "__main__":
    main()
