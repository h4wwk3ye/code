#!/usr/bin/env python3
# coding: utf-8
#Last Modified: 29/Oct/29 11:33:55 AM


import sys

def isPrime(n) : 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True

    if (n % 2 == 0 or n % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True

def main():
    n=int(input())
    b = 4
    while True:
        a = n+b
        if isPrime(a) or isPrime(b):
            b+=1
        else:
            print(a, b)
            break


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
