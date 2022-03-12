#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <14/Jun/2019 10:22:47 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


def query(i, lb, ub):
    print('Q', i, lb, ub, flush=True)
    s = input()
    return True if s == 'Yes' else False


def main():
    from bisect import bisect_left as lower_bound
    from bisect import bisect_right as upper_bound
    from bisect import insort_left
    for tc in range(int(input())):
        t = 0
        n = int(input())
        arr = [0, n + 1]
        x = [-1] * (n + 2)
        parent = [0] * (n + 1)
        root = False
        while len(arr) != n + 2:
            for i in range(n, 0, -1):
                if i in arr:
                    continue
                if root == False:
                    lb, ub = 1, n
                else:
                    lb = lower_bound(arr, i)
                    lb -= 1
                    lb = arr[lb]
                    lb += 1
                    ub = upper_bound(arr, i)
                    ub = arr[ub]
                    ub -= 1

                if lb == i and root == True:
                    t += 1
                    x[i] = t
                    insort_left(arr, i)
                    lb = lower_bound(arr, i)
                    lb -= 1
                    ub = upper_bound(arr, i)
                    lb = arr[lb]
                    ub = arr[ub]
                    #print(lb, ub, x[lb], x[ub], arr[lb], arr[ub])
                    if x[lb] > x[ub]:
                        parent[i] = lb
                    else:
                        parent[i] = ub

                else:
                    ans = query(i, lb, ub)

                    if ans == True:
                        t += 1
                        x[i] = t
                        insort_left(arr, i)
                        if root == False:
                            parent[i] = -1
                            root = True
                        else:
                            lb = lower_bound(arr, i)
                            lb -= 1
                            ub = upper_bound(arr, i)
                            lb = arr[lb]
                            ub = arr[ub]
                            #print(lb, ub, x[lb], x[ub], arr[lb], arr[ub])
                            if x[lb] > x[ub]:
                                parent[i] = lb
                            else:
                                parent[i] = ub

                # print(arr)
        print("A", *parent[1:], flush=True)


if __name__ == "__main__":
    main()
