import math
import os
import random
import re
import sys

# Complete the insertionSort1 function below.


def insertionSort1(n, arr):
    flag = 0
    item = arr[n-1]
    i = n-1
    while(True):
        if item < arr[i-1] and i != 0:
            arr[i] = arr[i-1]
            i -= 1
            print(*arr)
        elif i == 0:
            arr[i] = item
            print(*arr)
            break
        else:
            arr[i] = item
            print(*arr)
            break


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    insertionSort1(n, arr)
