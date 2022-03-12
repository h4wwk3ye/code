from itertools import product
for _ in range(int(input())):
    top = input()
    bottom = input()
    list_of_list = []
    flag = 0
    for i in range(3):
        list = []
        list.append(top[i])
        list.append(bottom[i])
        list_of_list.append(list)
    # print(list_of_list)
    for check in product(*list_of_list):
        str = ''
        for j in range(3):
            str += check[j]
        if str == 'bbo' or str == 'obb' or str == 'bob':
            flag = 1
            print('yes')
            break
    if flag == 0:
        print('no')
