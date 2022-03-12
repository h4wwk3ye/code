
from itertools import permutations
for t in range(int(input())):
    a,b=map(int,input().split())
    binary_a=format(a,'b')
    binary_b=format(b,'b')
    print(binary_a,binary_b)

    print(list(permutations(binary_a)))
