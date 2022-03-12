import sys


def isPrime(n):
    # Corner cases
    if (n <= 1):
        return False
    if (n <= 3):
        return True

    # This is checked so that we can skip
    # middle five numbers in below loop
    if (n % 2 == 0 or n % 3 == 0):
        return False

    i = 5
    while(i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i = i + 6

    return True

# print all prime numbers
# less than equal to N


def printPrime(n):
    primes = []
    for i in range(2, n + 1):
        if isPrime(i):
            primes.append(i)
    return primes


def main():

    n = int(sys.stdin.readline())

    arr = [int(i) for i in sys.stdin.readline().split()]
    if n == 1:
        print(0)
        return
    sum_arr = [0]*(n+1)
    sum_arr[1] = arr[0]
    for i in range(2, n+1):
        sum_arr[i] = sum_arr[i-1]+arr[i-1]
    primes = printPrime(n)
    dp = [0]*(n+1)
    for i in range(2, n+1):
        dp[i] = dp[i-1]
        j = 0
        while j < len(primes) and primes[j] <= i:
            v = i-primes[j]-1
            #print(v, i, primes[j], sum_arr[i], dp[v], sum_arr[v+1])
            if i-primes[j] == 0:
                dp[i] = max(dp[i], sum_arr[i])
            else:
                dp[i] = max(dp[i], dp[i-primes[j]-1]+sum_arr[i]-sum_arr[i-primes[j]])
            j += 1
    print(dp[n])


if __name__ == '__main__':
    main()
