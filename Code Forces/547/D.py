#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <19/Mar/2019 09:55:00 PM>


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
    L = input().strip()
    R = input().strip()
    d1, d2 = {}, {}
    for j in range(n):
        i = L[j]
        if i not in d1:
            d1[i] = []
        d1[i].append(j)

    for j in range(n):
        i = R[j]
        if i not in d2:
            d2[i] = []
        d2[i].append(j)

    # print(d1)
    # print(d2)
    ans = 0
    op = []
    rn1 = 0
    rn2 = 0
    ind1 = []
    ind2 = []
    for i in d1:
        if i == '?':
            continue
        if i in d2:
            ans += min(len(d1[i]), len(d2[i]))

            x = min(len(d1[i]), len(d2[i]))

            for l in range(x):
                op.append((d1[i][l]+1, d2[i][l]+1))

            if (len(d1[i]) > len(d2[i])):
                rn1 += len(d1[i])-len(d2[i])
                for l in range(x, len(d1[i])):
                    ind1.append(d1[i][l]+1)

            elif len(d2[i]) > len(d1[i]):
                rn2 += len(d2[i])-len(d1[i])
                for l in range(x, len(d2[i])):
                    ind2.append(d2[i][l]+1)
        else:
            rn1 += len(d1[i])
            for l in range(len(d1[i])):
                ind1.append(d1[i][l]+1)

    for i in d2:
        if i == '?':
            continue
        if i in d1:
            continue
        rn2 += (len(d2[i]))
        for l in range(len(d2[i])):
            ind2.append(d2[i][l]+1)

    #print(rn1, rn2)
    # print(ans)
    rm1 = 0
    rm2 = 0

    # print(op)
    # print(ind1)
    # print(ind2)

    if "?" in d1:
        ans += min(rn2, len(d1["?"]))
        x = min(len(d1["?"]), rn2)
        for l in range(x):
            op.append((d1["?"][l]+1, ind2[l]))
        if len(d1["?"]) > rn2:
            rm1 = len(d1["?"])-rn2

    if "?" in d2:
        ans += min(rn1, len(d2["?"]))
        x = min(rn1, len(d2["?"]))
        for l in range(x):
            op.append((ind1[l], d2["?"][l]+1))
        if len(d2["?"]) > rn1:
            rm2 = len(d2["?"])-rn1

    ans += min(rm1, rm2)
    for l in range(min(rm1, rm2)):
        op.append((d1["?"][(-l-1)]+1, d2["?"][(-l-1)]+1))

    print(ans)
    for i in op:
        print(i[0], i[1])


if __name__ == "__main__":
    main()
