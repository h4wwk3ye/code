# https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/booboo-and-upsolving-circuits/
def check(mid):
    count = 1
    curr_time = 0

    for i in time:
        curr_time += i
        if curr_time > mid:
            count += 1
            curr_time = i
        #print(count, curr_time)
    return count <= m


def find_min_time():
    low = 0
    high = sum(time)
    ans = high
    job_max = max(time)

    #print(ans, low, high)
    while low <= high:
        mid = (low+high)//2
        # print(mid)
        if mid >= job_max and check(mid):
            ans = min(ans, mid)
            high = mid-1
        else:
            low = mid+1
        #print(ans, mid, low, high)
    return ans


if __name__ == '__main__':
    n, m = map(int, input().split())
    time = list(map(int, input().split()))
    print(find_min_time())
