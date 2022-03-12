n_1, n_2, n_3 = map(int, input().split())
array_1 = list(map(int, input().split()))
# array_1.reverse()
array_2 = list(map(int, input().split()))
# array_2.reverse()
array_3 = list(map(int, input().split()))
# array_3.reverse()

sum_1 = sum(array_1)
sum_2 = sum(array_2)
sum_3 = sum(array_3)

top1 = top2 = top3 = 0
flag = 1

while(sum_1 != sum_2 or sum_1 != sum_3):
    if max(sum_1, sum_2, sum_3) == sum_1:
        remove = array_1[top1]
        top1 += 1
        sum_1 -= remove
        if top1 >= n_1:
            print('0')
            flag = 0
            break
    elif max(sum_1, sum_2, sum_3) == sum_2:
        remove = array_2[top2]
        sum_2 -= remove
        top2 += 1
        if top2 >= n_2:
            flag = 0
            print('0')
            break
    else:
        remove = array_3[top3]
        sum_3 -= remove
        top3 += 1
        if top3 >= n_3:
            flag = 0
            print('0')
            break
if flag == 1:
    print(sum_1)
