
import bisect

if __name__ == '__main__':
    semi_primes = [6, 10, 14, 15, 21, 22, 26, 33, 34, 35, 38, 39, 46, 51, 55, 57, 58, 62, 65, 69, 74, 77, 82, 85, 86, 87, 91, 93, 94, 95,
                   106, 111, 115, 118, 119, 122, 123, 129, 133, 134, 141, 142, 143, 145, 146, 155, 158, 159, 161, 166, 177, 178, 183, 185, 187, 194, 201, 202]
    sum_semi = []
    for i in range(len(semi_primes)):
        for j in range(i, len(semi_primes)):
            bisect.insort_left(sum_semi, semi_primes[i]+semi_primes[j])
    # print(sum_semi)
    for t in range(int(input())):
        n = int(input())
        index = bisect.bisect_left(sum_semi, n)
        if sum_semi[index] == n:
            print('YES')
        else:
            print('NO')
