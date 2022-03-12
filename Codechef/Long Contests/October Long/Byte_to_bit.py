if __name__ == '__main__':
    for t in range(int(input())):
        n = int(input())
        array = [1, 0, 0]
        fact = n//26
        if fact:
            array[0] = 2**fact
        n = n % 26
        flag = 1
        if n % 26 == 0:
            flag = 0
            print(*[0, 0, 2**(fact-1)])
        elif n <= 2:
            array = array
        elif n <= 10:
            array[0], array[1] = array[1], array[0]
        else:
            array[0], array[2] = array[2], array[0]
        if flag == 1:
            print(*array)
