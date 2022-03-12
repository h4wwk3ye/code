#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <23/Aug/2019 09:02:02 AM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


def main():
    arr = [i for i in range(1, 101)]
    print("?", *arr, flush=True)
    n = int(input())

    arr = [(i * 128) for i in range(1, 101)]
    print("?", *arr, flush=True)
    m = int(input())

    for i in range(1, 101):
        for j in range(1, 101):
            if (i ^ (j * 128)) == (n ^ m):
                print("!", n ^ i, flush=True)
                return


if __name__ == "__main__":
    main()
