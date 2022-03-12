str = list(input())
n = int(input())
new_str = []
for _ in range(n):
    i, k = map(int, input().split())
    for j in range(0, i):
        convert_j = ord(str[j])
        if convert_j+k > 122:
            convert_j = k+96-(122-convert_j)
        else:
            convert_j += k
        str[j] = chr(convert_j)
print(*str, sep='')
