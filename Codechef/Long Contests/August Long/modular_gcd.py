
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def reduce(a, b):
    mod = 0
    for i in range(0, len(b)):
        mod = (mod*10+ord(b[i])) % a
    return mod


def gcd_large(a, b):
    num = reduce(a, b)
    return gcd(a, num)


for _ in range(int(input())):
    a, b, n = map(int, input().split())
    string = ''
    string += str(a**n+b**n)
    print(gcd_large(a-b, string) % (10**9+7))
