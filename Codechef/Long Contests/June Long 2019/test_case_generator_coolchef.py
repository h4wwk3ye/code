from random import randint
f = open("inp.txt", "w")
n = randint(1, 3 * 10**5 + 1)
q = randint(1, 3 * 10**5 + 1)
f.write(str(n) + " ")
f.write(str(q) + "\n")
arr = [0] * n
for i in range(n):
    arr[i] = randint(1, 10**9 + 1)
    f.write(str(arr[i]) + " ")
f.write("\n")
for i in range(q):
    l1 = randint(0, n - 1)
    l2 = randint(0, n - 1)
    r1 = randint(0, n - 1)
    r2 = randint(0, n - 1)
    f.write(str(l1) + " " + str(l2) + " " + str(r1) + " " + str(r2) + "\n")
