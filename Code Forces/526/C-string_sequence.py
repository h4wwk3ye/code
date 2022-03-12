import sys


def main():
    s = sys.stdin.readline()
    count = 0
    mod = 10**9+7
    i, n = 0, len(s)
    while i < n and s[i] != 'a':
        i += 1
    ans = 1
    while i < n:
        if s[i] == 'a':
            count += 1
        elif s[i] == 'b':
            ans = (ans*(1+count)) % mod
            count = 0
        i += 1
    ans = (ans*(1+count)) % mod
    print(ans-1, sep=' ', end='\n', file=sys.stdout, flush=False)


if __name__ == '__main__':
    main()
