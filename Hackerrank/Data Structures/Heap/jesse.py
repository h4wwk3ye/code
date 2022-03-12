import heapq

if __name__ == '__main__':
    n, k = map(int, input().split())
    array = list(map(int, input().split()))
    heapq.heapify(array)
    count = 0
    flag = 0
    while array[0] < k:
        x = heapq.heappop(array)
        if len(array) == 0:
            print(-1)
            flag = 1
            break
        y = heapq.heappop(array)
        heapq.heappush(array, x+2*y)
        count += 1

    if flag == 0:
        print(count)
