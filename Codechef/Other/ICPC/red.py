if __name__ == '__main__':
    for _ in range(int(input())):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        arr.sort()
        arr_other = [arr[i] for i in range(n)]
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
        a = sum(arr)
        if n > 3:
            index = 0
            while index < n-3:
                if arr_other[index] > k:
                    arr_other[index] = k
                index += 1
            total = sum(arr_other[:n-3])
            p = arr_other[n-2]-k
            q = arr_other[n-3]-p
            r = arr_other[n-2]-p
            total_other = total+q+r+arr_other[-1]
            if total_other < a:
                print(a)
            else:
                print(total_other)
            # print(arr_other)
        else:
            print(a)
