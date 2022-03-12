import sys
if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    m = {}
    m[0] = 1
    odd, even, ans = 0, 0, 0
    for i in arr:
        if i & 1:
            odd += 1
        else:
            even += 1
        if odd-even not in m:
            m[odd-even] = 1
        else:
            ans += m[odd-even]
            m[odd-even] += 1
    print(ans, sep=' ', end='\n', file=sys.stdout, flush=False)
