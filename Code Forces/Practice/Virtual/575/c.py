#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <15/Oct/2019 12:00:44 AM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    for tc in range(int(input())):
        n = int(input())
        arr = [0] * n
        for i in range(n):
            arr[i] = get_array()
        x1, y1 = -10 ** 5 - 1, -10 ** 5 - 1
        x2, y2 = 10 ** 5 + 1, 10 ** 5 + 1
        f = 0
        for i in range(n):
            if arr[i][3] == 0:
                f = 1
                y2 = min(y2, arr[i][1])
            if arr[i][2] == 0:
                f = 1
                x1 = max(x1, arr[i][0])
            if arr[i][4] == 0:
                f = 1
                x2 = min(x2, arr[i][0])
            if arr[i][5] == 0:
                f = 1
                y1 = max(y1, arr[i][1])

        if f == 0:
            print(1, 1, 1)
            continue
        if y1 > y2 or x1 > x2:
            print(0)
        else:
            print(1, end=" ")
            if x1 == -10 ** 5 - 1 and x2 == 10 ** 5 + 1:
                print(0, end=" ")
            else:
                if x1 != -10 ** 5 - 1:
                    print(x1, end=" ")
                else:
                    print(x2, end=" ")

            if y1 == -10 ** 5 - 1 and y2 == 10 ** 5 + 1:
                print(0, end=" ")
            else:
                if y1 != -10 ** 5 - 1:
                    print(y1, end=" ")
                else:
                    print(y2, end=" ")
            print()


BUFSIZE = 8192


class FastIO(BytesIO):
    newlines = 0

    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0, 2), super(FastIO, self).write(s))[0])
        return s

    def read(self):
        while self._fill():
            pass
        return super(FastIO, self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill()
            self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        py2 = round(0.5)
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2 == 1:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s: self.buffer.write(s.encode("ascii"))
            self.read = lambda: self.buffer.read().decode("ascii")
            self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def get_ints():
    return map(int, sys.stdin.readline().split())


def input():
    return sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
