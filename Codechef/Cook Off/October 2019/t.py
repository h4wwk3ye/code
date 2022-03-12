import sys

sys.stdout = open("F:\Codechef\Cook Off\October 2019\inp.txt", "w")
print(3000)
from random import randint

a = []
for i in range(3000):
    a.append(randint(1, 10 ** 9))
print(*a)
