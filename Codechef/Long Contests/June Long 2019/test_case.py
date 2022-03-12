from random import randint
f = open("inp.txt", "w")
tc = randint(1, 100)
f.write(str(tc) + "\n")
for _ in range(tc):
    n = randint(1, 100)
    m = randint(1, 100)
    k = randint(1, 100)
    f.write(str(n) + " " + str(m) + " " + str(k) + "\n")
