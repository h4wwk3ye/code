if __name__ == '__main__':
    stack_1 = []
    stack_2 = []
    for _ in range(int(input())):
        query = list(map(int, input().split()))
        if query[0] == 1:
            stack_1.append(query[1])
        elif query[0] == 2:
            if not stack_2:
                while stack_1:
                    stack_2.append(stack_1.pop())
            stack_2.pop()
        else:
            if not stack_2:
                while stack_1:
                    stack_2.append(stack_1.pop())
            top = stack_2.pop()
            print(top)
            stack_2.append(top)
