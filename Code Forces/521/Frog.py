if __name__ == '__main__':
    for t in range(int(input())):
        a, b, k = map(int, input().split())
        time = k//2
        rem = k % 2
        poistion = (a-b)*time
        if rem != 0:
            poistion += a

        print(poistion)
