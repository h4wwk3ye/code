import sys
if __name__ == '__main__':
    d = {}
    d['monday'] = 1
    d['tuesday'] = 2
    d['wednesday'] = 3
    d['thursday'] = 4
    d['friday'] = 5
    d['saturday'] = 6
    d['sunday'] = 7
    for tc in range(int(input())):
        s, e, l, r = input().split()
        l = int(l)
        r = int(r)
        x = d[s]
        y = d[e]
        if x >= y:
            y += 7
        #print(x, y)
        if l > y-x+1 and r-l <= 7:
            print('impossible')
        elif r-l > y-x:
            print('many')
        elif r-l == y-x:
            print(r-l)
