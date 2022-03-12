#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <01/Jun/2019 11:47:24 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


from math import sqrt, acos, atan2, sin, cos, pi, tan, atan
import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(float, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    # https://www.math10.com/en/geometry/geogebra/fullscreen.html
    Px, Py, Dx, Dy, a = get_ints()
    Cx, Cy = 0, 0

    def check_intersection(x1, y1, x2, y2, a):
        x3, y3 = 0, 0
        px = x2 - x1
        py = y2 - y1
        norm = px * px + py * py
        u = ((x3 - x1) * px + (y3 - y1) * py) / norm
        if u > 1:
            u = 1
        elif u < 0:
            u = 0
        x = x1 + u * px
        y = y1 + u * py
        dx = x - x3
        dy = y - y3
        dist = sqrt(dx * dx + dy * dy)
        if dist > a:
            return 'outside'
        else:
            return 'inside'

    check = check_intersection(Px, Py, Dx, Dy, a)

    if check == 'outside':
        dist = float("inf")
        inc = 1e-3
        x = 0
        y = a
        X, Y = 0, 0
        while True:
            curr = (a**2 - x**2)
            if curr < 0:
                break
            y = sqrt(curr)
            d = sqrt((Px - x)**2 + (Py - y)**2)
            d += sqrt((Dx - x)**2 + (Dy - y)**2)
            if d < dist:
                X = x
                Y = y
                dist = d
            x += inc
        dist = round(dist, 6)
        print("{:.6f}".format(dist))
        return
    else:
        # print('inside')
        b = sqrt((Px - Cx)**2 + (Py - Cy)**2)
        th = acos(a / b)
        d = atan2(Py - Cy, Px - Cx)
        d1 = d + th
        d2 = d - th

        S1x = Cx + a * cos(d1)
        S1y = Cy + a * sin(d1)
        S2x = Cx + a * cos(d2)
        S2y = Cy + a * sin(d2)

        b = sqrt((Dx - Cx)**2 + (Dy - Cy)**2)
        th = acos(a / b)
        d = atan2(Dy - Cy, Dx - Cx)
        d1 = d + th
        d2 = d - th

        T1x = Cx + a * cos(d1)
        T1y = Cy + a * sin(d1)
        T2x = Cx + a * cos(d2)
        T2y = Cy + a * sin(d2)

        d1 = sqrt((Px - S1x)**2 + (Py - S1y)**2)
        d2 = sqrt((Dx - T1x)**2 + (Dy - T1y)**2)

        d = sqrt((S1x - T1x)**2 + (S1y - T1y)**2)
        ang = acos(1 - (d**2 / (2 * a * a)))
        l = a * ang

        d = sqrt((S1x - T2x)**2 + (S1y - T2y)**2)
        ang = acos(1 - (d**2 / (2 * a * a)))
        l = min(l, a * ang)

        d = sqrt((S2x - T1x)**2 + (S2y - T1y)**2)
        ang = acos(1 - (d**2 / (2 * a * a)))
        l = min(l, a * ang)

        d = sqrt((S2x - T2x)**2 + (S2y - T2y)**2)
        ang = acos(1 - (d**2 / (2 * a * a)))
        l = min(l, a * ang)
        dist = l + d1 + d2
        dist = round(dist, 6)
        print("{:.6f}".format(dist))


main()
