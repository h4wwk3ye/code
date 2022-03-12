import sys


def main():
    n = int(input())
    arr = list(input().split())
    scores = [0] * n
    for i in range(n):
        tmp = sorted(arr[i])
        scores[i] = str(int(tmp[0]) * 7 + int(tmp[-1]) * 11)
        if len(scores[i]) <= 2:
            continue
        scores[i] = scores[i][-2:]

    even, odd = {}, {}
    for i in range(0, n, 2):
        if int(scores[i][0]) not in even:
            even[int(scores[i][0])] = 0
        even[int(scores[i][0])] += 1
    for i in range(1, n, 2):
        if int(scores[i][0]) not in odd:
            odd[int(scores[i][0])] = 0
        odd[int(scores[i][0])] += 1
    ans = 0

    flag = [0] * 10
    for k in even:
        cnt = even[k]
        if cnt <= 1:
            continue
        if cnt == 2:
            if k in odd:
                if odd[k] > 2:
                    ans += 2
                    flag[k] = 1
                elif odd[k] == 2:
                    ans += 1
                    flag[k] = 1
                else:
                    ans += 1
                    flag[k] = 1
            else:
                ans += 1
        else:
            flag[k] = 1
            ans += 2

    for k in odd:
        if flag[k] == 1:
            continue
        cnt = odd[k]
        if cnt <= 1:
            continue
        if cnt == 2:
            ans += 1
        else:
            ans += 2

    print(ans)


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
