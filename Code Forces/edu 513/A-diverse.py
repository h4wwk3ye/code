import sys
if __name__ == '__main__':
    n = int(input())
    s = sys.stdin.readline()
    flag = 0
    for i in range(n-1):
        if s[i] != s[i+1]:
            flag = 1
            print('YES')
            print(s[i], s
            break
    if flag == 0:
        print('NO')
