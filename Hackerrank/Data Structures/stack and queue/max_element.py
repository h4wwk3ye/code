stack = []
max = [0]
for _ in range(int(input())):
    arr = list(map(int, input().split()))
    if arr[0] == 1:
        stack.append(arr[1])
        if arr[1] >= max[-1]:
            max.append(arr[1])
    if arr[0] == 2:
        check = stack.pop()
        if check == max[-1]:
            max.pop()
    if arr[0] == 3:
        print(max[-1])
