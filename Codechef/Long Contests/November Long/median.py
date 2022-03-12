import sys
import statistics
import bisect


def even_subsequences(L):
    # yield the empty subsequence

    # iterate over subsequence starting points
    for i in range(len(L)):
        # subsequence end point is the starting point plus an even number
        for j in range(i+2, len(L)+1, 2):
            # slice the list
            yield L[i:j]


if __name__ == '__main__':
    for tc in range(int(input())):
        n = int(input())
        arr = list(map(int, sys.stdin.readline().split()))
        subsequence = list(even_subsequences(arr))
        # print(subsequence)
        # print(arr)
        count = 2**n-1-len(subsequence)
        for element in subsequence:
            element.sort()
            length = len(element)
            if element[(length//2)-1] == element[length//2]:
                # print(element)
                count += 1
                count %= (10**9+7)

        print(count)
