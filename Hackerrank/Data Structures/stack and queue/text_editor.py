if __name__ == '__main__':
    str_stack = str()
    backup = []
    #check = []
    for _ in range(int(input())):
        operation = input().split()
        op = int(operation[0])
        if op != 4:
            do = operation[1]
        if op == 1:
            if str_stack or backup:
                backup.append(str_stack)
            str_stack += do
        elif op == 2:
            backup.append(str_stack)
            new_str = str_stack[0:len(str_stack)-int(do)]
            str_stack = new_str
        elif op == 3:
            print(str_stack[int(do)-1])
            # check.append(str_stack[int(do)-1])
        elif op == 4:
            if backup:
                str_stack = backup.pop()
            else:
                str_stack = str()

    # print(check)
