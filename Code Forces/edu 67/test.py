from random import randint


def f(a, b, c):
    return(a - min(b, c) + 1)


def se(a, b, c):
    n = b + c - a
    return max(b - n, c - n) + 1


tc = randint(1, 10**6)
for _ in range(tc):
    n = randint(1, 10**9)
    s = randint(1, n)
    t = randint(n - s, n)
    #print(n, s, t)
    if (f(n, s, t) != se(n, s, t)):
        print(n, s, t)
