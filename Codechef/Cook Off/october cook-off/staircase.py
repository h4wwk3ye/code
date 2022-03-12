if __name__ == '__main__':
    for t in range(int(input())):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        count = 0
        height = 0
        i = 0
        while i < n:
            if arr[i]-height <= k:
                height = arr[i]
                i += 1
            else:
                height += k
                count += 1

        print(count)
