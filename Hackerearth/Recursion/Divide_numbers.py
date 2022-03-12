from math import sqrt
import sys
if __name__ == '__main__':
    for tc in range(int(input())):
        n = int(input())
        factors = []
        i = 1
        while i <= sqrt(n):
            if n/i == i:
                factors.append(i)
            else:
                factors.append(i)
                factors.append(n//i)
            i += 1
        length = len(factors)
        maximum = 0
        for i in range(length):
            for j in range(length):
                for k in range(length):
                    for l in range(length):
                        if factors[i]+factors[j]+factors[k]+factors[l] == n:
                            maximum = max(maximum, factors[i]*factors[j]*factors[k]*factors[l])
        print(maximum)
