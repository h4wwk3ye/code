import sys


def main():
    n, r = map(int, sys.stdin.readline().split())
    for i in range(n):
        x = int(sys.stdin.readline())
        if x >= r:
            print('Good boi', sep=' ', end='\n', file=sys.stdout, flush=False)
        else:
            print('Bad boi', sep=' ', end='\n', file=sys.stdout, flush=False)


if __name__ == '__main__':
    main()
