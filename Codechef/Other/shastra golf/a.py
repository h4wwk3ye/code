import sys

sys.stdin = open("F:/Code/Codechef/Other/shastra golf/a.txt", "r")

arr = []
for i in range(120):
    a, b = map(int, input().split())
    arr.append(b)

print(arr)
