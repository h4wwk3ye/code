import sys


def main():
    n = int(input())
    arr = [0]*n
    for i in range(n):
        arr[i] = int(input())
    sum_1 = 1
    sum_2 = 1
    check_1 = [1]*n
    check_2 = [1]*n
    for i in range(1, n):
        if arr[i] > arr[i-1]:
            sum_1 += 1
        else:
            sum_1 = 1
        check_1[i] = sum_1
    for i in range(n-2, -1, -1):
        if arr[i] > arr[i+1]:
            sum_2 += 1
        else:
            sum_2 = 1
        check_2[i] = sum_2
    total = 0
    for i in range(n):
        total += max(check_1[i], check_2[i])
    print(total)


if __name__ == '__main__':
    main()
