from random import randint
import sys

sys.stdout = open("inp.txt", "w")
n = randint(2, 10 ** 3)
g = randint(2, n)
print(n)
print(g)
for i in range(n):
    x = randint(1, 10 ** 3)
    y = randint(1, 10 ** 3)
    print(x, y)
