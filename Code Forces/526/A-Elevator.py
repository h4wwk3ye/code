import sys
import operator


def main():
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    arr = list(enumerate(arr))
    arr.sort(key=operator.itemgetter(1), reverse=True)
    # print(arr)
    check = arr[0][1]
    index = -1
    while index < n - 1 and arr[index][1] == check:
        index += 1
    count = 0
    # print(index)
    # print(arr[index][0])
    for i in range(n):

        # if arr[i][0] <= arr[index][0]:
            #count += arr[i][1]*(2*(abs(arr[index][0]-arr[i][0]))+2*(arr[i][0]))
        # else:
        count += 2 * (arr[i][1] * 2 * (arr[i][0]))
    print(count)


if __name__ == '__main__':
    main()
