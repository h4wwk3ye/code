import sys


def profit(arr, low, high):
    if low > high:
        return 0
    year = N-(high-low+1)+1
    if cache[low][high] != -1:
        return cache[low][high]
    cache[low][high] = max(profit(arr, low+1, high)+year*arr[low],
                           profit(arr, low, high-1)+year*arr[high])
    return cache[low][high]


def main():
    arr = [1, 3, 4, 2]
    print(profit(arr, 0, 3))


if __name__ == '__main__':
    N = 4
    cache = [[-1 for _ in range(N)]for _ in range(N)]
    main()
