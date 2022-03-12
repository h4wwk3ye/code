import sys
if __name__ == '__main__':
    n = int(input())
    stack = list(map(int, sys.stdin.readline().split()))
    stack.reverse()
    order = list(map(int, sys.stdin.readline().split()))
    order.reverse()
    books = [False for _ in range(n+1)]
    output = []
    while order:
        book = order.pop()
        if books[book]:
            output.append(0)

        else:
            count = 0
            for j in range(len(stack)-1, -1, -1):
                if stack[j] != book:
                    k = stack[j]
                    stack.pop()
                    count += 1
                    books[k] = True
                else:
                    k = stack[j]
                    stack.pop()
                    count += 1
                    books[k] = True
                    break
            output.append(count)
    print(*output)
