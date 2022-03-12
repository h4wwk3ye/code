for t in range(int(input())):
    n = int(input())
    count = 0
    for i in range(n):
        s, j = map(int, input().split())
        if j-s > 5:
            count += 1
    print(count)
