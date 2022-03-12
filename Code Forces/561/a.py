fact = [0] * 101
fact[1] = 1
for i in range(2, 101):
    fact[i] = fact[i - 1] * i


def nCr(n, r):
    if n == r:
        return 1
    return fact[n] // (fact[r] * fact[n - r])


def main():
    n = int(input())
    arr = [0] * n
    for i in range(n):
        arr[i] = input()[:1]
    from collections import Counter
    d = Counter(arr)

    ans = 0
    for i in d:
        if d[i] <= 2:
            continue
        x = d[i] // 2
        if d[i] % 2 == 1:
            ans += nCr(x + 1, 2)
            ans += nCr(x, 2)
        else:
            ans += 2 * nCr(x, 2)
    print(ans)


if __name__ == "__main__":
    main()
