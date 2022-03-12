def search(mid):
    print(mid, 'yes')
    x = string_b.copy()
    for i in range(mid+1):
        x[i] = '1'

    return 1 if x >= string_a else 0


if __name__ == '__main__':
    n, q = map(int, input().split())
    string_a = list(input())
    string_b = list(input())
    queries = [None]*q
    for i in range(q):
        x = int(input())
        queries[i] = x-1

    low = 0
    high = q-1
    ans = float('inf')
    while low <= high:
        mid = (low+high)//2
        if search(mid):
            high = mid-1
            ans = min(ans, mid)
        else:
            low = mid+1
    print(ans)
