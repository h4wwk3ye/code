for _ in range(int(input())):
    brackets = input()
    stack = []
    flag = 1
    for i in brackets:
        if i == '(' or i == '{' or i == '[':
            stack.append(i)
        elif i == ')':
            if not stack:
                print('NO')
                flag = 0
                break
            if stack.pop() != '(':
                print('NO')
                flag = 0
                break
        elif i == '}':
            if not stack:
                print('NO')
                flag = 0
                break
            if stack.pop() != '{':
                print('NO')
                flag = 0
                break
        elif i == ']':
            if not stack:
                print('NO')
                flag = 0
                break
            if stack.pop() != '[':
                print('NO')
                flag = 0
                break
    if flag == 1 and not stack:
        print('YES')
    if flag == 1 and stack:
        print('NO')
