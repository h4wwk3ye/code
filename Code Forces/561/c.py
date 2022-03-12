def main():
    n = int(input())
    arr = [abs(int(a)) for a in input().split()]
    arr.sort()
    from bisect import bisect
    ans = 0
    for i in range(n):
        j = bisect(arr, 2 * arr[i])
        ans += max(0, j - i - 1)
    print(ans)


if __name__ == "__main__":
    main()
