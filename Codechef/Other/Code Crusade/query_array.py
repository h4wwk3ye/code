if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    q = int(input())
    for i in range(q):
        l, r, x = map(int, input().split())
        if x in arr[l:r+1]:
            print('yes')
        else:
            print('no')
