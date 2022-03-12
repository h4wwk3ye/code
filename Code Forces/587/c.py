#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <21/Sep/2019 02:26:18 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    x1, y1, x2, y2 = get_ints()
    x3, y3, x4, y4 = get_ints()
    x5, y5, x6, y6 = get_ints()

    ans = "YES"

    if x5 <= x1 and y5 <= y1 and x6 >= x2 and y6 >= y2:
        ans = "NO"
    elif x3 <= x1 and y3 <= y1 and x4 >= x2 and y4 >= y2:
        ans = "NO"

    else:
        if y6 >= y3 and y5 <= y3:
            if y5 <= y1 and y4 >= y2:
                if x5 <= x4 and x3 <= x5:
                    if x3 <= x1 and x5 >= x2:
                        ans = "NO"
                elif x3 <= x6 and x5 <= x3:
                    if x4 >= x2 and x5 <= x1:
                        ans = "NO"
        elif y4 >= y5 and y5 >= y3:
            if y6 >= y2 and y3 <= y1:
                if x5 <= x4 and x3 <= x5:
                    if x3 <= x1 and x5 >= x2:
                        ans = "NO"
                elif x3 <= x6 and x5 <= x3:
                    if x4 >= x2 and x5 <= x1:
                        ans = "NO"
    print(ans)


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
