def f(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6):

    flag = 0

    if x3 <= x1 and x4 >= x2:
        if y3 <= y1 and y4 >= y2:
            flag = 1

    if x5 <= x1 and x6 >= x2:
        if y5 <= y1 and y6 >= y2:
            flag = 1

    if x3 <= x1 and x4 >= x2:
        if x5 <= x1 and x6 >= x2:
            if y3 <= y1 and y5 <= y4 and y6 >= y2:
                flag = 1

    if x3 <= x1 and x4 >= x2:
        if x5 <= x1 and x6 >= x2:
            if y5 <= y1 and y3 <= y6 and y4 >= y2:
                flag = 1

    if y3 <= y1 and y4 >= y2:
        if y5 <= y1 and y6 >= y2:
            if x3 <= x1 and x5 <= x4 and x6 >= x2:
                flag = 1

    if y3 <= y1 and y4 >= y2:
        if y5 <= y1 and y6 >= y2:
            if x5 <= x1 and x3 <= x6 and x4 >= x2:
                flag = 1

    if flag == 0:
        return "YES"
    else:
        return "NO"


def s(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6):
    mn = [10 ** 9] * (10 ** 6 + 5)
    mx = [-1] * (10 ** 6 + 5)
    for i in range(x3, x4):
        mx[i] = y4
        mn[i] = y3
    for i in range(x5, x6):
        mx[i] = max(mx[i], y6)
        mn[i] = min(mn[i], y5)

    ans = "NO"
    for i in range(x1, x2):
        # print(i, mn[i], mx[i])
        if mn[i] == 10 ** 9 or mx[i] == -1:
            ans = "YES"
            break
        if y1 < mn[i] or y2 > mx[i]:
            ans = "YES"
            break
    return ans


import sys

sys.stdin = open("inp.txt", "r")
for tc in range(int(input())):
    x1, y1, x2, y2 = map(int, input().split())
    x3, y3, x4, y4 = map(int, input().split())
    x5, y5, x6, y6 = map(int, input().split())
    if f(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6) != s(
        x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6
    ):
        print(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6)
