import sys
from decimal import *
if __name__ == '__main__':
    inp = list(map(int, sys.stdin.readline().split()))
    tc = inp[0]
    i = 1
    output = [None]*26
    output[0] = 0
    output[1] = 0.5
    for i in range(2, 26):
        output[i] = (output[i-2]+output[i-1])/2
    # print(output)
    i = 1
    for tc in range(tc):
        n = inp[i]
        print(*Decimal(output[n]).as_integer_ratio(), end=' ')
        i += 1
