if __name__ == '__main__':
    for t in range(int(input())):
        n, x, s = map(int, input().split())
        for _ in range(s):
            a, b = map(int, input().split())
            if x == a:
                x = b
            elif x == b:
                x = a
        print(x)
