from collections import defaultdict
if __name__ == '__main__':
    n, m, k = map(int, input().split())
    #tracks = [[None for i in range(m)] for j in range(n)]
    total = 0
    d = defaultdict(list)
    for i in range(k):
        a, b, c = map(int, input().split())
        if a in d:
            d[a][0][0] = min(b, d[a][0][0])
            d[a][0][1] = max(c, d[a][0][1])
        else:
            d[a].append([b, c])
    for i in d:
        # print(d[i][0][0])
        total += (d[i][0][1]-d[i][0][0]+1)
    print(n*m-total)
