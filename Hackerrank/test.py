#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <16/Apr/2019 10:17:05 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()

# ///==========MAIN=============///


if __name__ == "__main__":
    key = 'theallieswin'
    d = {}
    posi = {}
    matrix = [[-1] * 9 for _ in range(4)]
    index = 0
    for i in range(4):
        for j in range(9):
            while index < len(key) and key[index] in d:
                index += 1
            if index == len(key):
                break
            matrix[i][j] = key[index]
            d[key[index]] = 1
            posi[key[index]] = (i, j)
        if index == len(key):
            break
    curr = 97
    for i in range(4):
        for j in range(9):
            if (matrix[i][j] != -1):
                continue
            while curr <= 122 and (chr(curr)) in d:
                curr += 1
            if curr == 123:
                break
            matrix[i][j] = chr(curr)
            d[matrix[i][j]] = 1
            posi[matrix[i][j]] = (i, j)
            curr += 1
            if (curr == 123):
                break
        if (curr == 123):
            break
    curr = 0
    for i in range(4):
        for j in range(9):
            if matrix[i][j] != -1:
                continue
            matrix[i][j] = curr
            posi[curr] = (i, j)
            curr += 1
    '''for i in range(4):
        print(*matrix[i])
    # print(posi)'''

    plain_text = input()
    if len(plain_text) % 2 == 1:
        plain_text += 'x'
    ans = ''
    for i in range(0, len(plain_text), 2):
        if plain_text[i] == plain_text[i + 1]:
            a = plain_text[i]
            b = 'x'
        else:
            a = plain_text[i]
            b = plain_text[i + 1]
        x1, y1 = posi[a]
        x2, y2 = posi[b]
        fx, fy = x2, y1
        sx, sy = x1, y2
        ans += matrix[fx][fy]
        ans += matrix[sx][sy]
    print(ans)

    ciphert = input()
    if len(ciphert) % 2 == 1:
        ciphert += 'x'
    ans = ''
    for i in range(0, len(ciphert), 2):
        if ciphert[i] == ciphert[i + 1]:
            a = ciphert[i]
            b = 'x'
        else:
            a = ciphert[i]
            b = ciphert[i + 1]
        x1, y1 = posi[a]
        x2, y2 = posi[b]
        fx, fy = x2, y1
        sx, sy = x1, y2
        ans += matrix[fx][fy]
        ans += matrix[sx][sy]
    print(ans)
