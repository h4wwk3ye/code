import sys
if __name__ == '__main__':
    for _ in range(int(input())):
        s = list(input())
        n = len(s)
        boolean_arr = [False for i in range(n)]
        flag = 1
        for i in range(n):
            if s[i] != '.':
                k = int(s[i])
                for j in range(k+1):
                    if i+j < n:
                        if boolean_arr[i+j] != False:
                            flag = 0
                            break
                        boolean_arr[i+j] = True
                if flag == 0:
                    break
        for i in range(n-1, -1, -1):
            if s[i] != '.':
                k = int(s[i])
                for j in range(-1, -(k+1), -1):
                    if (i+j) >= 0:
                        if boolean_arr[i+j] != False:
                            flag = 0
                            break
                        boolean_arr[i+j] = True
                if flag == 0:
                    break
        # print(boolean_arr)
        if flag == 1:
            print('safe')
        else:
            print('unsafe')
