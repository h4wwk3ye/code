from collections import defaultdict
from math import sqrt


def calc_dist(x1, y1, x2, y2):
    x = abs(x1-x2)
    y = abs(y1-y2)
    return x+y


if __name__ == '__main__':
    for t in range(int(input())):
        n, m = map(int, input().split())
        grid = []
        for i in range(n):
            grid.append(list(input()))
        # print(grid)
        vertices = []
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    vertices.append([i+1, j+1])

        # print(vertices)
        distances = {}
        for i in range(len(vertices)):
            for j in range(i+1, len(vertices)):
                dist = calc_dist(*vertices[i], *vertices[j])
                if dist not in distances:
                    distances[dist] = 0
                distances[dist] += 1
        # print(distances)
        output = []
        for i in range(1, n+m-1):
            if i not in distances:
                output.append(0)
            else:
                output.append(distances[i])
        print(*output)
