import sys


def main():
    for tc in range(int(sys.stdin.readline())):
        n = int(sys.stdin.readline())
        arr = [None]*n
        print(1, 1, 2, 3, sep=' ', end='\n', file=sys.stdout, flush=True)
        p = int(sys.stdin.readline())
        print(1, 2, 3, 4, sep=' ', end='\n', file=sys.stdout, flush=True)
        q = int(sys.stdin.readline())
        r = p ^ q   # a xor d
        print(1, 1, 4, 5, sep=' ', end='\n', file=sys.stdout, flush=True)
        e = int(sys.stdin.readline())
        arr[4] = e ^ r
        print(1, 1, 4, 6, sep=' ', end='\n', file=sys.stdout, flush=True)
        f = int(sys.stdin.readline())
        arr[5] = f ^ r
        for i in range(7, n+1, 2):
            print(1, i-2, i-1, i, sep=' ', end='\n', file=sys.stdout, flush=True)
            u = int(sys.stdin.readline())
            arr[i-1] = arr[i-3] ^ arr[i-2] ^ u

            if i+1 <= n:
                print(1, i-2, i-1, i+1, sep=' ', end='\n', file=sys.stdout, flush=True)
                u = int(sys.stdin.readline())
                arr[i] = arr[i-3] ^ arr[i-2] ^ u
        print(1, 2, n-1, n, sep=' ', end='\n', file=sys.stdout, flush=True)
        u = int(sys.stdin.readline())
        arr[1] = u ^ arr[-1] ^ arr[-2]
        if n % 2 == 0:
            print(1, 3, n-1, n, sep=' ', end='\n', file=sys.stdout, flush=True)
            u = int(sys.stdin.readline())
            arr[2] = u ^ arr[-1] ^ arr[-2]
        else:
            print(1, 3, n, n-2, sep=' ', end='\n', file=sys.stdout, flush=True)
            u = int(sys.stdin.readline())
            arr[2] = u ^ arr[-1] ^ arr[-3]

        arr[0] = p ^ arr[1] ^ arr[2]
        arr[3] = q ^ arr[1] ^ arr[2]
        print(2, *arr, sep=' ', end='\n', file=sys.stdout, flush=True)
        check = int(sys.stdin.readline())


if __name__ == '__main__':
    main()
