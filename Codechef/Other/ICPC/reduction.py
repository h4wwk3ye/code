if __name__ == '__main__':
    while True:
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        arr.sort()
        index = 0
        while index < n:
            while index < n:
                if arr[index] > k:
                    break
                index += 1
            if index+1 < n:
                p = arr[index]-k
                arr[index] -= p
                arr[index+1] -= p
            else:
                break
        print(sum(arr))
