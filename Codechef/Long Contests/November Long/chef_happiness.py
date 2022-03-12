import sys
from collections import defaultdict
if __name__ == '__main__':
    for tc in range(int(input())):
        n = int(input())
        arr = list(map(int, sys.stdin.readline().split()))
        arr.insert(0, 0)
        flag = 0
        check = defaultdict(list)
        for i in range(1, n+1):
            check[arr[i]].append(i)
        #print(check, sep=' ', end='\n', file=sys.stdout, flush=False)
        for i in check:
            # print(i)
            if len(check[i]) >= 2:
                count = 0
                for j in check[i]:
                    #print(j, end=' ')
                    if j in check:
                        count += 1
                    if count == 2:
                        flag = 1
                        break
                # print('')
                if flag == 1:
                    break
        if flag == 0:
            print('Poor Chef')
        else:
            print('Truly Happy')
