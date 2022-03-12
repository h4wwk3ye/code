from random import randint
import sys
sys.stdout = open("inp.txt", "w")
t = 3
print(3)
n = randint(1, 10**5)
m = randint(n + 1, 2 * 10**5)
print(n, m, 1)
arr = [0] * n
for i in range(n):
    arr[i] = randint(1, 10**3)
print(*arr)

for _ in range(2, n + 1):
    print(1, _)

for _ in range(n, m):
    u = randint(2, 10**5)
    v = randint(2, 10**5)
    print(u, v)
