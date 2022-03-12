def gcd(a, b):
    if a == b:
        return a
    if a % 2 == 0 and b % 2 == 0:
        return 2*gcd(a//2, b//2)
    elif a % 2 == 0:
        return gcd(a//2, b)
    elif b % 2 == 0:
        return gcd(a, b//2)
    else:
        c = max(a, b)
        d = min(a, b)
        return gcd((c-d)//2, d)


for _ in range(int(input())):
    a, b, n = map(int, input().split())
    sum = a**n+b**n
    diff = a-b
    print(gcd(sum, diff) % (10**9+7))
