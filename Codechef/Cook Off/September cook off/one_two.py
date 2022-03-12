from itertools import combinations
for t in range(int(input())):
    n = int(input())
    array = list(map(int, input().split()))
    dictionary = {}
    for start, end in combinations(range(n), 2):
        total = sum(array[start:end+1])
        if sum not in dictionary:
            dictionary[sum] = 1
    for i in range(n):

    print(len(dictionary)+n)
