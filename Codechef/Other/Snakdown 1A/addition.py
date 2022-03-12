from itertools import *
import sys
sys.setrecursionlimit(1500)


def binary(num, length):
    return format(num, '0{}b'.format(length))


def count_setbits(n):
    count = 0
    while n:
        n &= (n-1)
        count += 1
    return count


def next_permutation(a):
    """Generate the lexicographically next permutation inplace.

    https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    Return false if there is no next permutation.
    """
    # Find the largest index i such that a[i] < a[i + 1]. If no such
    # index exists, the permutation is the last permutation
    for i in reversed(range(len(a) - 1)):
        if a[i] < a[i + 1]:
            break  # found
    else:  # no break: not found
        return False  # no next permutation

    # Find the largest index j greater than i such that a[i] < a[j]
    j = next(j for j in reversed(range(i + 1, len(a))) if a[i] < a[j])

    # Swap the value of a[i] with that of a[j]
    a[i], a[j] = a[j], a[i]

    # Reverse sequence from a[i + 1] up to and including the final element a[n]
    a[i + 1:] = reversed(a[i + 1:])
    return True


if __name__ == '__main__':
    for t in range(int(input())):
        a, b, c = map(int, input().split())
        #binary_c = "{0:0b}".format(c)
        length = c.bit_length()
        #binary_a = binary(a, length)
        #binary_b = binary(b, length)
        v = []
        count_a = count_setbits(a)
        count_b = count_setbits(b)
        for i in range(length-count_a):
            v.append(0)
        for i in range(count_a):
            v.append(1)
        original = v
        count = 0
        while True:
            s = int(''.join(str(x) for x in v), 2)
            if c > s:
                bits = count_setbits(c-s)
                if bits == count_b:
                    count += 1
            else:
                break
            if next_permutation(v) == False:
                break
        print(count)
