from collections import defaultdict
if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    indices = []
    count = 0
    total = sum(arr)
    d = defaultdict(list)
    for i in range(n):
        d[arr[i]].append(i)
    for i in range(n):
        if (total-arr[i])/2 in d:
            #print(arr[i], d[(total-arr[i])//2])
            for j in d[(total-arr[i])//2]:
                # print(arr[j])
                if i != j and arr[j] == total-arr[i]-arr[j]:
                    #print(arr[j], total-arr[i]-arr[j])
                    # print('found')
                    count += 1
                    indices.append(i+1)
                break

    print(count)
    print(*indices)
