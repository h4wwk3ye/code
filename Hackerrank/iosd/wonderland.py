import bisect
array = []
for _ in range(int(input())):
    array.append(int(input()))

array.sort()
length = len(array)
totalsum = 0
while(len(array) >= 2):
    sum = (array[0]+array[1]) % (10**9+7)
    del array[0:2]
    bisect.insort(array, sum)
    totalsum += sum

print(totalsum % (10**9+7))
