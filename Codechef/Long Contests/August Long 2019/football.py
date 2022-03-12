for tc in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        ans = max(A[i]*20-B[i]*10, ans)
    print(ans)
