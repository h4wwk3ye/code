def recurse(n):
    if n < 0:
        return 0
    if n == 0 or n == 1:
        return 1
    if flag_arr[n]:
        return flag_arr[n]
    flag_arr[n] = recurse(n-1)+recurse(n-2)+recurse(n-3)
    return flag_arr[n]


if __name__ == '__main__':
    n = int(input())
    flag_arr = [None]*(n+1)
    flag_arr[0] = 0
    print(recurse(n))
