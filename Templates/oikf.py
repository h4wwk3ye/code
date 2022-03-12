s = input()
y = input()

sum = 0
n = len(s)
for i in range(1, len(y)):
    sum += n - i
for i in range(n - len(y)):
    x = int(s[i : i + len(y)])
    if x <= int(y):
        sum += 1
print(sum)
