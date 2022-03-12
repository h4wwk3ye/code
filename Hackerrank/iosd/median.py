str = list(input())
length = len(str)
new_str = [-1]*length
if length % 2 == 1:
    back = length-1
    front = 0
    for i in range(length-1, -1, -1):
        if i % 2 == 0:
            new_str[back] = str[i]
            back -= 1
        else:
            new_str[front] = str[i]
            front += 1
if length % 2 == 0:
    back = length-1
    front = 0
    for i in range(length-1, -1, -1):
        if i % 2 == 0:
            new_str[front] = str[i]
            front += 1
        else:
            new_str[back] = str[i]
            back -= 1

print(*new_str, sep='')
