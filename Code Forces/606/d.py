#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 14/Dec/19 11:56:39 PM


import sys


def main():
    for tc in range(int(input())):
        n = int(input())
        arr = [""] * n
        zz, oz, zo, oo = 0, 0, 0, 0
        A = {}
        B = {}
        d = {}
        di = {}
        f = 0
        for i in range(n):
            x = input()
            arr[i] = x[0] + x[-1]
            if arr[i] == "00":
                zz += 1
            elif arr[i] == "11":
                oo += 1
            elif arr[i] == "10":
                oz += 1
                A[x] = i + 1
                if x in d:
                    p = list(x)
                    p.reverse()
                    p = "".join(p)
                    if p in di:
                        f = 1
                    else:
                        di[p] = 1
                    if d[x] == 2:
                        f = 1
                    d[x] = 2
                d[x] = 1
            else:
                zo += 1
                B[x] = i + 1
                di[x] = 1
                if x in di:
                    p = list(di)
                    p.reverse()
                    p = "".join(p)
                    if p in d:
                        f = 1
                    else:
                        d[p] = 1
                    if di[x] == 2:
                        f = 1
                    di[x] = 2
                di[x] = 1

        if f == 1:
            print(-1)
            continue
        tmp = list(di.items())

        for i in tmp:
            p = list(i[0])
            p.reverse()
            p = "".join(p)
            if p in d:
                oz -= 1
                zo -= 1
                del d[p]
                del A[p]
                p = i[0]
                del di[p]
                del B[p]

        X, Y = [], []
        for i in A:
            X.append(A[i])
        for j in B:
            X.append(B[j])

        if oo != 0 and zz != 0 and (oz == 0 and zo == 0):
            print(-1)
            continue
        ans = 0
        op = []
        i = 0
        if zo > oz:
            while zo - 1 > oz:
                if i == len(X):
                    f = 1
                    break
                zo -= 1
                oz += 1
                ans += 1
                op.append(X[i])
                i += 1
        elif oz > zo:
            while oz - 1 > zo:
                if i == len(Y):
                    f = 1
                    break
                zo += 1
                oz -= 1
                ans += 1
                op.append(Y[i])
                i += 1
        if f == 1:
            print(-1)
            continue
        print(ans)
        print(*op)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
