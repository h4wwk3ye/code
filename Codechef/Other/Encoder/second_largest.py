import sys
if __name__ == '__main__':
    for _ in range(int(input())):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        max_count = 1
        for i in range(n-1):
            count = 1
            if arr[i] > k:
                for j in range(i+1, n):
                    # print(arr[i:j+1])
                    if arr[j] <= k:
                        count += 1
                    if arr[j] > k:
                        break
                # print(count)
                max_count = max(count, max_count)
            else:
                j = i+1
                while j < n and arr[j] <= k:
                    count += 1
                    j += 1
                if j < n:
                    curr = arr[j]
                    while j < n and (arr[j] <= k or arr[j] == curr):
                        count += 1
                        j += 1
                max_count = max(count, max_count)
            if max_count == n:
                break
        print(max_count)
