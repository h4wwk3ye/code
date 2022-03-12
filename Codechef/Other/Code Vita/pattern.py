n = int(input())
cnt = 0
x = n
while x > 0:
    cnt += 2 * x
    x -= 1
flag = [0] * (n + 1)
front = 1
back = cnt
curr = 0
x = n
while x > 0:
    if x != n:
        for i in range(curr):
            print('*', sep='', end='')
    print(front, end='')
    for i in range(front + 1, front + x):
        print('0', i, sep='', end='')
        front = i + 1
    for i in range(cnt - x + 1, cnt + 1):
        print('0', i, sep='', end='')
    cnt = cnt - x
    print()
    x -= 1
    curr += 2
