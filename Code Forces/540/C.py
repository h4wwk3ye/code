#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <19/Feb/2019 10:14:43 PM>


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
    n = int(input())
    arr = get_array()
    matrix = [[-1] * n for _ in range(n)]
    from collections import Counter
    s = Counter(arr)
    x, y = 0, 0
    l, m = 0, 0
    flag = 0
    for i in s:
        if s[i] % 4 != 0:
            if flag == 3:
                print('NO')
                return
            flag += 1
            if n % 2 == 0:
                print('NO')
                return
            if s[i] % 2 == 1 and flag == 1:
                matrix[n // 2][n // 2] = i
                s[i] -= 1
            elif s[i] % 2 == 0:
                if flag == 2:
                    matrix[n // 2][0] = i
                    matrix[n // 2][n - 1] = i
                    s[i] -= 2
                elif flag == 3:
                    matrix[0][n // 2] = i
                    matrix[n - 1][n // 2] = i
                    s[i] -= 2

    for p in s:
        while s[p] > 0:
            flag = 0
            for i in range(n):
                for j in range(n):
                    x, y = i, j
                    if matrix[i][j] != -1:
                        continue
                    #print(i, j)
                    if n % 2 == 1:
                        if y == n // 2:
                            matrix[i][j] = p
                            matrix[n - i - 1][j] = p
                            s[p] -= 2
                            if s[p] == 0:
                                flag = 1
                                break
                        elif x == n // 2:
                            matrix[i][j] = p
                            matrix[i][n - j - 1] = p
                            s[p] -= 2
                            if s[p] == 0:
                                flag = 1
                                break
                        else:
                            matrix[x][y] = p
                            matrix[x][n - y - 1] = p
                            matrix[n - x - 1][y] = p
                            matrix[n - x - 1][n - y - 1] = p
                            flag = 1
                            break
                    else:
                        matrix[x][y] = p
                        matrix[x][n - y - 1] = p
                        matrix[n - x - 1][y] = p
                        matrix[n - x - 1][n - y - 1] = p
                        flag = 1
                        break

                if flag == 1:
                    s[p] -= 4
                    if s[p] <= 0:
                        break

    print('YES')
    for i in range(n):
        print(*matrix[i])


if __name__ == "__main__":
    main()
