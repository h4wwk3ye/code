import bisect
if __name__ == '__main__':
    for tc in range(int(input())):
        truth = [0]*101
        dare = [0]*101
        t_p = int(input())
        t_perform = list(map(int, input().split()))
        for i in t_perform:
            truth[i] = 1

        d_p = int(input())
        d_perform = list(map(int, input().split()))
        for i in d_perform:
            dare[i] = 1

        t_s = int(input())
        t_shyam = list(map(int, input().split()))

        d_s = int(input())
        d_shyam = list(map(int, input().split()))

        flag = 0

        for i in t_shyam:
            if truth[i] == 0:
                flag = 1
                break
        if flag == 0:
            for i in d_shyam:
                if dare[i] == 0:
                    flag = 1
                    break
        if flag:
            print('no')
        else:
            print('yes')
