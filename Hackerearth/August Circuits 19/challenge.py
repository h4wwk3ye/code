import sys
import numpy as np

# sys.stdin = open("inp.txt", "r")

n = int(input())
g = int(input())

arr = [[list(map(int, input().split())), _] for _ in range(n)]


orig = np.array([0, 0])

arr = np.sort(arr, orig)

x = n // g

j = 0
op = {i: [] for i in range(x + 1)}
curr = 1
for i in range(x):
    cnt = 0
    while cnt != g:
        if j == n:
            break
        op[i].append(arr[j][1] + 1)
        j += 1
        cnt += 1
    curr += 1

for i in range(j, n):
    op[curr - 1].append(arr[i][1] + 1)


print(len(op))
for i in op:
    print(len(op[i]))
    print(*op[i])
