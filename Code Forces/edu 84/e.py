n = 5
ans = [0] * (n + 1)
o = 0

for i in range(10 ** n):
    x = list(str(i))
    while len(x) != n:
        x.insert(0, "0")

    curr = 1
    p = x[0]
    for j in range(1, len(x)):
        if x[j] != p:
            ans[curr] += 1
            curr = 1
            p = x[j]
        else:
            curr += 1
    ans[curr] += 1

x = [1]
s = 0
for i in range(1, n + 1):
    x.append(i * pow(10, i) - s * 2)

    s += x[-1]


x.reverse()
print(*x)
print(*ans)
