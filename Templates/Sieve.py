primes = []


def primes_sieve(limit):
    a = [True] * (limit + 1)
    a[0] = a[1] = False

    i = 0
    while i * i <= limit:
        if a[i] == True:
            for j in range(i * i, limit + 1, i):
                a[j] = False
        i += 1

    for i in range(2, limit + 1):
        if a[i] == True:
            primes.append(i)
