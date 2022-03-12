import sys
if __name__ == '__main__':
    n, q = map(int, sys.stdin.readline().split())
    binary = [None]*n
    for i in range(n):
        string = int(sys.stdin.readline(), 2)
        binary[i] = string
    for i in range(q):
        maximum = 0
        l, r, x = (sys.stdin.readline().split())
        l = int(l)
        r = int(r)
        x = int(x, 2)
        index = l-1
        for j in range(l-1, r):
            xor = binary[j] ^ x
            if maximum < xor:
                index = j
                maximum = xor
        print(index+1)
