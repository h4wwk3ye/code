n = int(input())
list = [input() for _ in range(n)]
list.sort()
list.sort(key=len)
for i in list:
    print(i)
