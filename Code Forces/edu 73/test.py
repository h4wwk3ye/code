tc = 10**4
import sys
sys.stdout = open("inp.txt", "w")
print(tc)
from random import randint

for _ in range(tc):
    c = randint(1, 10**8)
    m = randint(1, 10**8)
    x = randint(1, 10**8)
    print(c, m, x)
