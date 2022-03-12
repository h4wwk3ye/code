def max_area(h):
    n = len(h)
    max_area = -1
    for i in range(len(h)):  # loop for each building in histogram
        count = 0
        for j in range(i, -1, -1):        # loop for building behind the current building
            if h[j] >= h[i]:
                count += 1
            else:
                break
        for k in range(i+1, n):  # loop for building ahead
            if h[k] >= h[i]:
                count += 1
            else:
                break
        area = h[i]*count
        max_area = max(area, max_area)
    return max_area


if __name__ == '__main__':
    n = int(input())
    height = list(map(int, input().split()))
    print(max_area(height))
