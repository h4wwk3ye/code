if __name__ == '__main__':
    for t in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        count = 0
        i = 0
        while i < n:
            j = i+1
            while j < n:
                if arr[j] < arr[i]:
                    break
