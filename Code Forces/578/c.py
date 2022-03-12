#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <11/Aug/2019 09:24:46 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO
from math import gcd, ceil


def main():
    n, m, q = get_ints()
    g = gcd(n, m)
    # print(g)
    x = n//g
    y = m//g
    #print(x, y)
    for tc in range(q):
        sx, sy, ex, ey = get_ints()
        sy -= 1
        ey -= 1
        if sx == 1 and ex == 1:
            if (sy//x) == (ey//x):
                print('YES')
            else:
                print('NO')
        elif sx == 1 and ex == 2:
            if (sy//x) == (ey//y):
                print('YES')
            else:
                print('NO')
        elif sx == 2 and ex == 1:
            if (sy//y) == (ey//x):
                print('YES')
            else:
                print('NO')
        elif sx == 2 and ex == 2:
            if (sy//y) == (ey//y):
                print('YES')
            else:
                print('NO')


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


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
