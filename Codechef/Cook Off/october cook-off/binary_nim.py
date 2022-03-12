if __name__ == '__main__':
    for t in range(int(input())):
        n, s = input().split()
        n = int(n)
        stacks = []
        for i in range(n):
            stacks.append(input())
        x = 0
        y = 0
        for i in range(n):
            if stacks[i][0] == '0' and stacks[i][-1] == '0':
                x += 1
            elif stacks[i][0] == '1' and stacks[i][-1] == '1':
                y += 1
        if s == 'Dee':
            if x <= y:
                print('Dee')
            else:
                print('Dum')
        else:
            if x < y:
                print('Dee')
            else:
                print('Dum')
