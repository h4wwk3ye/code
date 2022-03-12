def main():
    n = int(input())
    arr = get_array()
    from collections import Counter
    d = Counter(arr)
    from operator import itemgetter
    d = sorted(d.items(), key=itemgetter(1), reverse=True)
    print(d[0][1])


if __name__ == "__main__":
    main()
