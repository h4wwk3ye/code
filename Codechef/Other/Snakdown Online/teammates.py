if __name__ == '__main__':
    for t in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        arr.sort()
        pairs = []
        for i in range(n):
            for j in range(1+i, n):
                pairs.append([arr[i], arr[j]])
        print(pairs)
        count = 0
        for i in range(len(pairs)):
            for j in range()
