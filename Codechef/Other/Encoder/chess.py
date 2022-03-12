import sys
if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        knights = []
        for i in range(n):
            a, b = map(int, input().split())
            knights.append([a, b])
        x, y = map(int, input().split())
        left = 0
        left_upper = 0
        left_lower = 0
        upper = 0
        lower = 0
        right = 0
        right_upper = 0
        right_lower = 0
        check = 0
        flag = 0
        for i in range(n):
            a, b = knights[i]
            if check == 0:
                if a-2 == x and b-1 == y:
                    check = 1
                elif a-2 == x and b+1 == y:
                    check = 1
                elif a+2 == x and b-1 == y:
                    check = 1
                elif a+2 == x and b+1 == y:
                    check = 1
                elif a-1 == x and b-2 == y:
                    check = 1
                elif a-1 == x and b+2 == y:
                    check = 1
                elif a+1 == x and b-2 == y:
                    check = 1
                elif a+1 == x and b+2 == y:
                    check = 1

            if a-2 == x-1 and b-1 == y+1:
                left_upper = 1
            elif a-2 == x-1 and b+1 == y+1:
                left_upper = 1
            elif a+2 == x-1 and b-1 == y+1:
                left_upper = 1
            elif a+2 == x-1 and b+1 == y+1:
                left_upper = 1
            elif a-1 == x-1 and b-2 == y+1:
                left_upper = 1
            elif a-1 == x-1 and b+2 == y+1:
                left_upper = 1
            elif a+1 == x-1 and b-2 == y+1:
                left_upper = 1
            elif a+1 == x-1 and b+2 == y+1:
                left_upper = 1

            if a-2 == x-1 and b-1 == y:
                left = 1
            elif a-2 == x-1 and b+1 == y:
                left = 1
            elif a+2 == x-1 and b-1 == y:
                left = 1
            elif a+2 == x-1 and b+1 == y:
                left = 1
            elif a-1 == x-1 and b-2 == y:
                left = 1
            elif a-1 == x-1 and b+2 == y:
                left = 1
            elif a+1 == x-1 and b-2 == y:
                left = 1
            elif a+1 == x-1 and b+2 == y:
                left = 1

            if a-2 == x-1 and b-1 == y-1:
                left_lower = 1
            elif a-2 == x-1 and b+1 == y-1:
                left_lower = 1
            elif a+2 == x-1 and b-1 == y-1:
                left_lower = 1
            elif a+2 == x-1 and b+1 == y-1:
                left_lower = 1
            elif a-1 == x-1 and b-2 == y-1:
                left_lower = 1
            elif a-1 == x-1 and b+2 == y-1:
                left_lower = 1
            elif a+1 == x-1 and b-2 == y-1:
                left_lower = 1
            elif a+1 == x-1 and b+2 == y-1:
                left_lower = 1

            if a-2 == x and b-1 == y+1:
                upper = 1
            elif a-2 == x and b+1 == y+1:
                upper = 1
            elif a+2 == x and b-1 == y+1:
                upper = 1
            elif a+2 == x and b+1 == y+1:
                upper = 1
            elif a-1 == x and b-2 == y+1:
                upper = 1
            elif a-1 == x and b+2 == y+1:
                upper = 1
            elif a+1 == x and b-2 == y+1:
                upper = 1
            elif a+1 == x and b+2 == y+1:
                upper = 1

            if a-2 == x and b-1 == y-1:
                lower = 1
            elif a-2 == x and b+1 == y-1:
                lower = 1
            elif a+2 == x and b-1 == y-1:
                lower = 1
            elif a+2 == x and b+1 == y-1:
                lower = 1
            elif a-1 == x and b-2 == y-1:
                lower = 1
            elif a-1 == x and b+2 == y-1:
                lower = 1
            elif a+1 == x and b-2 == y-1:
                lower = 1
            elif a+1 == x and b+2 == y-1:
                lower = 1

            if a-2 == x+1 and b-1 == y-1:
                right_lower = 1
            elif a-2 == x+1 and b+1 == y-1:
                right_lower = 1
            elif a+2 == x+1 and b-1 == y-1:
                right_lower = 1
            elif a+2 == x+1 and b+1 == y-1:
                right_lower = 1
            elif a-1 == x+1 and b-2 == y-1:
                right_lower = 1
            elif a-1 == x+1 and b+2 == y-1:
                right_lower = 1
            elif a+1 == x+1 and b-2 == y-1:
                right_lower = 1
            elif a+1 == x+1 and b+2 == y-1:
                right_lower = 1

            if a-2 == x+1 and b-1 == y:
                right = 1
            elif a-2 == x+1 and b+1 == y:
                right = 1
            elif a+2 == x+1 and b-1 == y:
                right = 1
            elif a+2 == x+1 and b+1 == y:
                right = 1
            elif a-1 == x+1 and b-2 == y:
                right = 1
            elif a-1 == x+1 and b+2 == y:
                right = 1
            elif a+1 == x+1 and b-2 == y:
                right = 1
            elif a+1 == x+1 and b+2 == y:
                right = 1

            if a-2 == x+1 and b-1 == y+1:
                right_upper = 1
            elif a-2 == x+1 and b+1 == y+1:
                right_upper = 1
            elif a+2 == x+1 and b-1 == y+1:
                right_upper = 1
            elif a+2 == x+1 and b+1 == y+1:
                right_upper = 1
            elif a-1 == x+1 and b-2 == y+1:
                right_upper = 1
            elif a-1 == x+1 and b+2 == y+1:
                right_upper = 1
            elif a+1 == x+1 and b-2 == y+1:
                right_upper = 1
            elif a+1 == x+1 and b+2 == y+1:
                right_upper = 1

            if check == 1 and left == 1 and left_lower == 1 and left_upper == 1 and upper == 1 and lower == 1 and right == 1 and right_upper == 1 and right_lower == 1:
                flag = 1
                break
        if check == 0:
            print('NO')
        elif check == 1 and flag == 0:
            print('NO')
        elif check == 1 and flag == 1:
            print('YES')
