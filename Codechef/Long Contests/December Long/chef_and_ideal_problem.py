import sys


def main():
    print(1)
    sys.stdout.flush()
    y = int(input())
    if y == 2:
        print(3)
    else:
        print(2)
    sys.stdout.flush()


if __name__ == '__main__':
    main()
