if __name__ == '__main__':
    for t in range(int(input())):
        a, b, k = map(int, input().split())
        total = a+b
        total = total % (2*k)
        if total < k:
            print('CHEF')
        else:
            print('COOK')
