#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <21/Sep/2019 07:25:34 PM>


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

    mn = [10 ** 9] * (10 ** 6 + 5)
    mx = [-1] * (10 ** 6 + 5)
    for i in range(x3, x4):
        mx[i] = y4
        mn[i] = y3
    for i in range(x5, x6):
        mx[i] = max(mx[i], y6)
        mn[i] = min(mn[i], y5)

    ans = "NO"
    for i in range(x1, x2):
        # print(i, mn[i], mx[i])
        if mn[i] == 10 ** 9 or mx[i] == -1:
            ans = "YES"
            break
        if y1 < mn[i] or y2 > mx[i]:
            ans = "YES"
            break
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
