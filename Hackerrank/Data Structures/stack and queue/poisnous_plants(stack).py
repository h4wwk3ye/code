from collections import deque


def check_plant(array):
    list_of_stacks = []
    left = 0
    right = 0
    i = 0
    while(i < len(array)-1):
        if array[i] >= array[i+1]:
            right += 1

        else:
            list_of_stacks.append(deque(array[left:right+1]))
            left = right = right+1
        i += 1
    list_of_stacks.append(deque(array[left:len(array)]))
    list_of_stacks = deque(list_of_stacks)
    '''while(len(list_of_stacks)!=1):
        for i in range(1,len(list_of_stacks)):
            del'''
    print(list_of_stacks)


if __name__ == '__main__':

    array = 0 == int(input()) or list(map(int, input().split()))
    print(check_plant(array))
