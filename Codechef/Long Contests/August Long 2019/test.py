'''from random import randint
import sys
sys.stdout = open("F:/Codechef/Long Contests/August Long 2019/inp.txt", "w")
tc = randint(1, 10)
print(tc)
for _ in range(tc):
    nl = 1
    l = randint(1, 10**18)
    print(1, l)
    r = randint(l, 10**18)
    print(1, r)
'''
#arr = [0]*10**8
# print(arr[-1])
import sys
mod = 10**9+7


def get_ints(): return map(int, sys.stdin.readline().split())


for tc in range(int(input())):
    nl, l = get_ints()
    nr, r = get_ints()
    ans = 0
    for i in range(l, r+1):
        x = str(i)
        n = len(x)-1
        prev = -1
        for j in x:
            if j != prev:
                ans += (int(j)*pow(10, n, mod)) % mod
            n -= 1
            prev = j
    ans %= mod
    print(ans)

'''print(1)
print(1, 10**18-5)
print(1, 10**18)'''
