def factorial(n):

    if cache[n] != -1:
        return cache[n]
    cache[n] = ((n % mod)*(factorial(n-1) % mod)) % mod
    return cache[n]


if __name__ == '__main__':
    mod = 10**9+7
    cache = [-1]*(10**5)
    cache[0] = 1
    cache[1] = 1
    tc = int(input())
    for tc in range(tc):
        n = int(input())
        print(factorial(n))
