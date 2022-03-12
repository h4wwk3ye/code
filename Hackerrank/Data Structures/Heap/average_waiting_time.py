import heapq
if __name__ == '__main__':
    dict = []
    n = int(input())
    for i in range(n):
        a, b = map(int, input().split())
        dict.append((a, b))
    dict.sort(reverse=True)
    array = []
    waiting_time = 0
    current_time = 0
    while dict or array:
        while dict and dict[-1][0] <= current_time:
            heapq.heappush(array, dict.pop()[::-1])
        if array:
            current = heapq.heappop(array)
            current_time += current[0]
            waiting_time += current_time-current[1]
        else:
            heapq.heappush(array, dict.pop()[::-1])
            current_time = dict[0][1]
    print(waiting_time//n)
