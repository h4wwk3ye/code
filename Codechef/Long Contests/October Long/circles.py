from math import sqrt
from math import ceil
from math import floor
import operator


def check(x1, y1, r1, x2, y2, r2, d):
    if (x1 == x2) and (y1 == y2) and (r1 == r2):
        return 'same'
    elif d == 0:
        return 'cocentric'
    elif r1+r2 == d:
        return 'external_touch'
    elif max(r1, r2) == min(r1, r2)+d:
        return 'internal_touch'
    elif r1+r2 < d:
        return 'disjoint'
    elif max(r1, r2) > d+min(r1, r2):
        return 'inside'
    elif r1+r2 > d:
        return 'intersect'


def dist(x1, y1, x2, y2):
    x = (x1-x2)**2
    y = (y1-y2)**2
    d = sqrt(x+y)
    return d


if __name__ == '__main__':
    n, q = map(int, input().split())
    circles = []
    for i in range(n):
        circles.append(list(map(int, input().split())))

    maximum = 10**6
    chk = [0]*maximum
    for i in range(n-1):
        for j in range(i+1, n):
            r1 = circles[i][2]
            r2 = circles[j][2]
            centre_distance = dist(circles[i][0], circles[i][1], circles[j][0], circles[j][1])
            type = check(*circles[i], *circles[j], centre_distance)
            a = 0
            b = 0
            if type == 'same':
                a = 0
                b = 0
            elif type == 'cocentric':
                a = max(r1, r2)-min(r1, r2)
                b = r1+r2
            elif type == 'external_touch':
                a = 0
                b = r1+centre_distance+r2
            elif type == 'internal_touch':
                a = 0
                b = max(r1, r2)*2
            elif type == 'disjoint':
                a = centre_distance-r1-r2
                b = centre_distance+r1+r2
            elif type == 'intersect':
                a = 0
                b = centre_distance+r1+r2
            elif type == 'inside':
                a = max(r1, r2)-centre_distance-min(r1, r2)
                b = r1+r2+centre_distance
            lower_index = ceil(a)
            chk[lower_index] += 1
            upper_index = floor(b)
            chk[upper_index+1] -= 1
    for i in range(1, maximum):
        chk[i] += chk[i-1]
    for p in range(q):
        k = int(input())
        print(chk[k])
