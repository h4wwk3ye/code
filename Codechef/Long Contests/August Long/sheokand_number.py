import math


def highest_power_of_2(n):
    power = int(math.log2(n))
    return int(pow(2, power))


for i in range(int(input())):
    n = int(input())
    nearest_no = highest_power_of_2(n)
    difference = n-nearest_no
    if difference == 0:
        print('1')
        continue
    less_than = highest_power_of_2(difference)
    greater_than = less_than*2
    times = min(difference-less_than, greater_than-difference)
    print(times)
