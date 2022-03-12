import math


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


'''def power(x, y, p):
    res = 1
    #print(x, y, p)
    x = x % p
    while(y > 0):
        if y % 2 != 0:
            res = (res*x) % p
        y = y//2
        x = (x*x) % p
        # print(x)
    return res'''


def power(x, y, p):
    if y == 0:
        return 1
    elif y % 2 == 0:
        z = power(x, y//2, p)
        return (z*z) % p
    else:
        return ((x % p)*power(x, y-1, p)) % p


for _ in range(int(input())):
    a, b, n = map(int, input().split())
    if a == b:
        print(power(a, n, 10**9+7)+power(b, n, 10**9+7))
    else:
        c = power(a, n, a-b)
        d = power(b, n, a-b)
        result = (c+d) % (a-b)
        print(gcd(a-b, result) % (10**9+7))
    # print(result)
    #print(a % (a-b))
