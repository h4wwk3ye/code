a = input()
b = list(input())
d = {}
for i in range(26):
    d[a[i]] = 2*i+1
    d[chr(ord(a[i]) - 32)] = 2*i


b.sort(key=lambda x: d[x])
print(*b,sep='')