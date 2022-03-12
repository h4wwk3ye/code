import math


def highest_power_of_2(n):
    power = int(math.log2(n))
    return power


for _ in range(int(input())):
    n = int(input())
    prev = 0
    current = 0
    flag = 0
    current_other = -1*10**9+1
    power = highest_power_of_2(n)
    if n == 1:
        print('2')
    elif 2**power == n:
        print('1')
    else:
        if (2**power+2**(power-1)) > n:
            for i in range(power-1, -1, -1):
                #prev = current
                calc = 2**power+2**i
                if calc == n:
                    current = calc
                    flag = 1
                    break
                if calc < n:
                    current_other = calc
                    flag = 1
                    break
                if flag == 1:
                    break
                current = calc
                #print(current, calc)
        else:
            no = 2**power+2**(power-1)
            smaller_diff = n-no
            no_2 = 2**(power+1)+1
            larger_diff = no_2-n
        if flag == 0:
            print(min(smaller_diff, larger_diff))
        elif flag == 1:
            print(min(current-n, n-current_other))
