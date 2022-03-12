from sys import stdin, stdout


def main():
    n, c = map(int, stdin.readline().split())
    low, high, count = 1, n, 0
    ans = n
    flag = 0
    if n == 1:
        check = int(input())
        print(2)
        stdout.flush()
        ans = 0
        print(3, ans+1, sep=' ', end='\n', file=stdout, flush=True)
    # elif n <= 1000:
        # for i in range(1, 1001):
        #    print(1, i, sep=' ', end='\n', file=stdout, flush=True)
        #check = int(stdin.readline())
        # if check == 1:
        #    print(2, sep=' ', end='\n', file=stdout, flush=True)
        #    print(3, i, sep=' ', end='\n', file=stdout, flush=True)
        #    break'''
    else:
        while True:
            print(1, low, sep=' ', end='\n', file=stdout, flush=True)
            count += 1
            check = int(stdin.readline())

            if check == 1:
                print(2, sep=' ', end='\n', file=stdout, flush=True)
                count += c
                if low == 1:
                    ans = 0
                    low = 1
                    high = 0
                    break
                high = low
                low = low//2
                '''if low == 0:
                    low = 1
                    high = 2'''

                break
            low *= 2
            if low >= n:
                low = low//2
                break
        if low != 1:
            factor = (high-low)//c
            if factor == 0:
                factor = 1
            # print(factor)
            while True:
                print(1, low, sep=' ', end='\n', file=stdout, flush=True)
                count += 1
                check = int(stdin.readline())
                if check == 1:
                    print(2, sep=' ', end='\n', file=stdout, flush=True)
                    count += c
                    high = low
                    low = prev
                    #low = int(low*2/3)
                    break
                prev = low
                low += factor
                if low >= n:
                    low = prev
                    break
        while low < high:
            if high-low < abs(999-count):
                flag = 1
                break
            mid = (low+high)//2
            print(1, mid)
            #print(mid, sep=' ', end='\n', file=stdout, flush=False)
            stdout.flush()
            count += 1
            check = int(stdin.readline())
            if check == 1:
                print(2, sep=' ', end='\n', file=stdout, flush=False)
                stdout.flush()
                high = mid
                count += c
                if mid == 1:
                    ans = 0
                    break

            elif check == 0:
                ans = mid
                low = mid+1
            #print(low, high, sep=' ', end='\n', file=stdout, flush=False)

        if flag == 1:
            for i in range(low, high+1):
                print(1, i, sep=' ', end='\n', file=stdout, flush=True)
                check = int(stdin.readline())
                count += 1
                if check == 1:
                    print(2, sep=' ', end='\n', file=stdout, flush=True)
                    count += c
                    ans = i-1
                    break

        print(3, ans+1, sep=' ', end='\n', file=stdout)
        stdout.flush()

    #print(count, sep=' ', end='\n', file=stdout, flush=False)


if __name__ == '__main__':
    main()
