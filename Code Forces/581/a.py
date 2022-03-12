ans = []
for i in range(0, 100):
    x = 4 ** i
    ans.append(int(bin(x)[2:]))

from bisect import bisect_left

s = int(input())
print(bisect_left(ans, s))
