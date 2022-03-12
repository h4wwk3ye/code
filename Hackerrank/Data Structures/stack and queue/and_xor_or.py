if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    stack = []
    max = 0
    for i in arr:  # gives us the smallest and second smallest elements in sub arrays in linear time
        while stack:
            top = stack[-1]             # i and top of stack gives us those 2 no in that sub array
            check = top ^ i
            if check > max:
                max = check
            if i < top:
                stack.pop()
            else:
                break
        stack.append(i)
    print(max)
