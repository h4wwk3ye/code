def solve(i, j, k):
    print(s[i:j + 1])
    if (s[i] == s[j]):
        k += 1
        if (i >= j - 1):
            return k
    if (i >= j - 1):
        return k
    return (solve(i + 1, j - 1, k) + solve(i + 1, j, k) + solve(i, j - 1, k))


s = input()
n = len(s)
print(solve(0, n - 1, 0))
