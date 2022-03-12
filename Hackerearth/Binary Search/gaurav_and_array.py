# https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/gaurav-and-subarray-3-787fb90a/
import bisect


def search(n, mid, k):
    for i in range(n-mid+1):
        if sum_arr[i+mid]-sum_arr[i] >= k:
            return True
    return False


def prefix_sum():
    for i in range(1, n+1):
        sum_arr[i] = sum_arr[i-1]+count_1[i-1]


if __name__ == '__main__':
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))
    binary = list(map(lambda x: '{0:b}'.format(x), arr))
    count_1 = list(map(lambda x: x.count('1'), binary))

    sum_arr = [0]*(n+1)
    prefix_sum()

    for q in range(q):
        k = int(input())
        low = 1
        high = n
        ans = -1
        while low <= high:
            mid = (low+high)//2
            if search(n, mid, k):
                high = mid-1
                ans = mid
            else:
                low = mid+1
        print(ans)
