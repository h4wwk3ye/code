import numpy as np
for t in range(int(input())):
    n, q = map(int, input().split())
    array_a = list(map(int, input().split()))
    array_b = list(map(int, input().split()))
    array_a = np.array(array_a)
    array_b = np.array(array_b)
    similarity = 0
    for i in range(n):
        if array_a[i] == array_b[i]:
            similarity += 1
    for i in range(q):
        x, y, z = map(int, input().split())
        l = x ^ similarity
        r = y ^ similarity
        c = z ^ similarity
        array_a[l-1:r] = c
        # print(array_a)
        count = 0
        for j in range(n):
            if array_a[j] == array_b[j]:
                count += 1
        similarity = count
        print(count)
