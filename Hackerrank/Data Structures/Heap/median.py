import bisect
if __name__ == '__main__':
    array = []
    n = int(input())
    size = 0
    for _ in range(n):
        bisect.insort_left(array, int(input()))
        size += 1
        if size % 2 == 1:
            print(array[size//2]+0.0)
        else:
            x = array[size//2]
            y = array[(size//2)-1]
            print(round((x+y)/2, 1))
    # print(array)
