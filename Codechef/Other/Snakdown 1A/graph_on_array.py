from collections import defaultdict
import math


def coprime(a, b):
    return math.gcd(a, b) == 1


if __name__ == '__main__':
    for t in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        check_47 = 0
        for i in range(n):
            if arr[i] != 47:
                check_47 = 1
                break
        if n == 1:
            print(0)
            print(*arr)
        elif check_47 == 0:
            arr[0] = 2
            print(0)
            print(*arr)
        else:
            index = 0
            flag = 1
            for i in range(n):
                visited = False
                for j in range(n):
                    if i != j and coprime(arr[i], arr[j]):
                        visited = True
                        break
                if visited == False:
                    index = i
                    flag = 0
                    break

            if flag == 1:
                print(0)
                print(*arr)
            else:
                arr[index] = 47
                print(1)
                print(*arr)
