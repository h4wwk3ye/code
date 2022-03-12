import sys
from collections import Counter
import bisect
if __name__ == '__main__':
    n, q, k = map(int, input().split())
    arr = list(input().split())
    count = 1
    d = []
    mul_set = Counter()
    for i in range(n-1):
        if arr[i] == arr[i+1]:
            count += 1
        else:
            d.append(count)
            count = 1
    d.append(count)
    total = 0
    for i in range(len(d)):
        total += d[i]
        if arr[total-1] == '1':
            mul_set[d[i]] += 1
    queries = input()
    maximum = max(mul_set)
    rotation = 0
    for i in range(len(queries)):
        query = queries[i]
        if query == '?':
            print(min(k, maximum))
        elif query == '!':
            first_element = arr[(n-rotation+100000*n) % n]
            last_element = arr[(n-1-rotation+100000*n) % n]
            if first_element == '1' and last_element == '1':
                first = d[0]
                mul_set[first] -= 1
                if mul_set[first] == 0:
                    del mul_set[first]
                mul_set[first+1] += 1
                d[0] += 1
                last = d[-1]
                mul_set[last] -= 1
                if mul_set[last] == 0:
                    del mul_set[last]
                d[-1] -= 1
                if d[-1] == 0:
                    d.pop()
                #print(maximum, 'yes')
                maximum = max(mul_set)
            elif first_element == '0' and last_element == '0':
                d[0] += 1
                d[-1] -= 1
                if d[-1] == 0:
                    d.pop()
                maximum = max(mul_set)
            elif first_element == '1' and last_element == '0':
                last = d[-1]
                d[-1] -= 1
                if d[-1] == 0:
                    d.pop()
                d.insert(0, 1)
                mul_set[1] += 1
                maximum = max(mul_set)
            elif first_element == '0' and last_element == '1':
                last = d[-1]
                mul_set[last] -= 1
                if mul_set[last] == 0:
                    del mul_set[last]
                mul_set[last-1] += 1
                d[-1] -= 1
                if d[-1] == 0:
                    d.pop()
                d.insert(0, 1)
                mul_set[1] += 1
                #print(maximum, 'yes')
                maximum = max(mul_set)
            rotation += 1
