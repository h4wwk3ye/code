from math import sqrt


def check(a):
    x = sqrt(a)
    return x == int(x)


if __name__ == '__main__':
    n = int(input())
