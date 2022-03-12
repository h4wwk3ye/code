for t in range(int(input())):
    n = int(input())
    b = list(map(int, input().split()))
    using_1 = 0
    using_bi = 0
    for i in range(1, n):
        new_using_1 = max(using_1, using_bi+abs(b[i-1]-1))
        new_using_bi = max(using_bi+abs(b[i]-b[i-1]), using_1+abs(b[i]-1))
        using_1, using_bi = new_using_1, new_using_bi
    print(max(using_1, using_bi))
