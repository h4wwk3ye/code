import sys

sys.stdout = open("inp.txt", "w")
print(10 ** 5)
from random import randint

for _ in range(10 ** 5):
    x1 = randint(0, 10 ** 6 - 100)
    y1 = randint(0, 10 ** 6 - 100)
    x2 = randint(x1 + 1, 10 ** 6)
    y2 = randint(y1 + 1, 10 ** 6)

    x3 = randint(0, 10 ** 6 - 100)
    y3 = randint(0, 10 ** 6 - 100)
    x4 = randint(x3 + 1, 10 ** 6)
    y4 = randint(y3 + 1, 10 ** 6)

    x5 = randint(0, 10 ** 6 - 100)
    y5 = randint(0, 10 ** 6 - 100)
    x6 = randint(x5 + 1, 10 ** 6)
    y6 = randint(y5 + 1, 10 ** 6)

    print(x1, y1, x2, y2)
    print(x3, y3, x4, y4)
    print(x5, y5, x6, y6)
