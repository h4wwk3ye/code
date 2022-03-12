def check_plant(array):

    count = 0
    while True:
        flag = 0
        for i in range(len(array)-1, 0, -1):
            if array[i] > array[i-1]:
                del array[i]
                flag = 1
        if flag == 1:
            count += 1
        if flag == 0:
            return count


if __name__ == '__main__':

    array = 0 == int(input()) or list(map(int, input().split()))
    print(check_plant(array))
