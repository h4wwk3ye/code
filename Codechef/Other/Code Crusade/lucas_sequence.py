'''def lucas(n):
    arr = [None]*n
    arr[0] = 2
    arr[1] = 1
    arr[2] = 3
    for i in range(3, n):
        arr[i] = arr[i-1]+arr[i-2]
    return arr'''


if __name__ == '__main__':
    for t in range(int(input())):
        s = list(input())
        d = {}
        for i in range(len(s)):
            if s[i] not in d:
                d[s[i]] = 0
            d[s[i]] += 1
        value = list(d.values())
        value.sort()
        if len(set(value)) < 3:
            print('UNFIT')
        else:
            i = 0
            j = i
            while i < len(value)-1 and j < len(value)-1:
                j = i+1
                if value[j] == value[i]:
                    value[j] = -1
                    j += 1
                else:
                    i = j+1
            new_values = []
            for i in range(len(value)):
                if value[i] != -1:
                    new_values.append(value[i])
            if new_values[0] == 1 and new_values[1] == 2:
                new_values[0], new_values[1] = new_values[1], new_values[0]
            flag = 0
            for i in range(2, len(new_values)):
                if new_values[i-2]+new_values[i-1] == new_values[i]:
                    flag = 1
                    break
            if flag == 0:
                print('UNFIT')
            else:
                print('FIT')
