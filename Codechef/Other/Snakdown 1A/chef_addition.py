from itertools import combinations


def binary(num, length=8):
    return format(num, '0{}b'.format(length))


def binary_permutations(lst, k):
    for comb in combinations(range(len(lst)), k):
        result = [0] * len(lst)
        for i in comb:
            result[i] = 1
        yield ''.join((str(i) for i in result))
        # print(result)
        # yield result


if __name__ == '__main__':
    for t in range(int(input())):
        a, b, c = map(int, input().split())
        binary_c = "{0:0b}".format(c)
        length = len(binary_c)
        binary_a = binary(a, length)
        binary_b = binary(b, length)
        count_a = binary_a.count('1')
        count_b = binary_b.count('1')
        combinations_a = []
        combinations_b = []
        for perm in binary_permutations(binary_a, count_a):
            if int(perm, 2) <= c:
                combinations_a.append(perm)

        '''for perm in binary_permutations(binary_b, count_b):
            if int(perm, 2) <= c:
                combinations_b.append(perm)
        # print(combinations_a)
        # print(combinations_b)
        # print(binary_c)
        count = 0
        for element_a in combinations_a:
            for element_b in combinations_b:
                #print(int(element_a, 2)+int(element_b, 2))
                if int(element_a, 2)+int(element_b, 2) == c:
                    count += 1
        print(count)'''
        print(combinations_a)
