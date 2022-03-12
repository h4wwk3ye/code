#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the insertionSort2 function below.


def insertionSort2(n, arr):
    count = 0
    for i in range(1, n):
        item = arr[i]
        j = i
        while(j-1 >= 0 and arr[j-1] > item):
            arr[j] = arr[j-1]
            j -= 1
            count += 1
        arr[j] = item
        # print(*arr)
    print(count)


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    insertionSort2(n, arr)
