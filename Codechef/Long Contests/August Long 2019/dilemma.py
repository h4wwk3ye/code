for tc in range(int(input())):
    s = input()
    cnt = 0
    for i in s:
        if i == '1':
            cnt += 1
    if cnt % 2 == 0:
        print('LOSE')
    else:
        print('WIN')
