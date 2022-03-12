def largestRectangle(h):
    n = len(h)
    array_2d = [[h[i] for i in range(n)] for _ in range(n)]

    # print(array_2d)

    max_area = 0
    for i in range(n):
        diagonal_area = h[i]  # only 1 building is selected
        if diagonal_area > max_area:
            max_area = diagonal_area
        for j in range(i+1, n):  # considering only the upper right part of matrix(bottom left is same)
            length = j-i+1
            minimum = min(array_2d[i][j-1], array_2d[i][j])  # min height
            array_2d[i][j] = minimum
            area = length*minimum
            if max_area < area:
                max_area = area

    # print(array_2d)
    return max_area


if __name__ == '__main__':
    n = int(input())
    h = list(map(int, input().split()))

    res = largestRectangle(h)
    print(res)
