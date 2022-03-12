if __name__ == '__main__':
    for t in range(int(input())):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        arr.sort(reverse=True)
        prev = None
        count = 0
        rank = 0
        for i in range(n):
            if not prev or arr[i] != prev:
                rank = count
                prev = arr[i]
                rank += 1
            if rank > k:
                break
            count += 1
        print(count)
