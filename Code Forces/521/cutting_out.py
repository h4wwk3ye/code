from itertools import permutations, combinations
import sys
if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    #x = list(permutations(arr, k))
    d = {}
    maximum = 0
    lst = []
    for i in permutations(arr, k):
        # print(i)
        if i not in d:
            d[i] = 0
        d[i] += 1
        if d[i] > maximum:
            maximum = d[i]
            lst = i
    # print(d)
    print(*lst, sep=' ', end='\n', file=sys.stdout, flush=False)
