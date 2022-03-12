import sys
if __name__ == '__main__':
    for tc in range(int(input())):
        s = list(input())
        n = len(s)
        count_red = 0
        count_green = 0
        for i in range(n-1):
            if s[i] == s[i+1]:
                if s[i] == 'R':
                    count_red += 1
                else:
                    count_green += 1
        if s[0] == s[-1]:
            if s[0] == 'R':
                count_red += 1
            else:
                count_green += 1
        if count_red == count_green and (count_red == 0 or count_green == 1):
            print('yes')
        else:
            print('no')
