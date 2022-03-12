def Divisors(n):
    ans = []
    from math import sqrt
    i = 1
    while i <= sqrt(n):
        if (n % i == 0):
            ans.append(i)
            ans.append(n // i)
        i += 1
    return sorted(ans)


def main():
    k = int(input())
    div = Divisors(k)

    i = 0
    j = len(div) - 1
    s = 'aeiou'

    while i < j:
        a = div[i]
        b = div[j]
        #print(a, b)
        if a < 5 or b < 5:
            i += 1
            j -= 1
            continue
        # print('here')
        matrix = [['a'] * b for _ in range(a)]
        ind = 0
        indi = 0
        for i in range(a):
            for j in range(0, 5):
                matrix[i][j] = s[(j + ind) % 5]
            for j in range(5, b):
                matrix[i][j] = s[(j + indi) % 5]
            indi += 1
            ind += 1

        for i in range(a):
            print(*matrix[i], sep='', end='')
        return

    print(-1)


if __name__ == "__main__":
    main()
