def max_area(h):
    stack = []
    i = 0
    max_area = -1
    while(i < len(h)):
        if not stack or h[i] >= h[stack[-1]]:
            stack.append(i)
            i += 1
        else:
            j = stack.pop()
            if not stack:
                area = h[j]*i
            else:
                area = h[j]*(i-1-stack[-1])
            max_area = max(area, max_area)
            #print(h[j], area)
    while stack:
        j = stack.pop()
        if not stack:
            area = h[j]*i
        else:
            area = h[j]*(i-1-stack[-1])
        #print(h[j], area)
        max_area = max(area, max_area)

    return max_area


if __name__ == '__main__':
    n = int(input())
    height = list(map(int, input().split()))
    print(max_area(height))
