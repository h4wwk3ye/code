def recurse(a, b):
    if a % b == 0:
        s = ['0']*a
        s[0] = '1'
        return s
    return recurse(b, a % b)


if __name__ == '__main__':
    for tc in range(int(input())):
        x, y = map(int, input().split())
        binary = recurse(x, y)
        length = len(binary)
        if length != x:
            p = x//length
            binary = (binary*p)
            p = x % length
            for i in range(p):
                binary.append(binary[i])
        binary = ''.join(str(a) for a in binary)
        # print(binary)
        print(int(binary, 2) % (10**9+7))
