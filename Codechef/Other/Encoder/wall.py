import sys
import bisect
from collections import deque
if __name__ == '__main__':
    for _ in range(int(input())):
        n, m = map(int, input().split())
        height = list(map(int, sys.stdin.readline().split()))
        color = list(map(int, sys.stdin.readline().split()))
        count = 0
        queue = deque()
        queue.append([height[0], color[0]])
        for i in range(1, n):
            while queue and height[i] >= queue[0][0]:
                queue.popleft()
            queue.insert(0, [height[i], color[i]])
        color_flag = [False]*(m+1)
        # print(queue)
        for i in range(len(queue)):
            if color_flag[queue[i][1]] == False:
                count += 1
                color_flag[queue[i][1]] = True
        print(count)
