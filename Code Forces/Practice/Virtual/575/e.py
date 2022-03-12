#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <15/Oct/2019 01:02:21 AM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    for tc in range(int(input())):
        b, w = get_ints()
        x, y = 3, 2
        if b > w:
            f = 1  # black
            b, w = w, b
            x += 1
        if w > 3 * b + 1:
            print("NO")
            continue
        ans = [(x - 1, y), (x, y + 1), (x, y - 1)]
        right = [(x + 1, y)]
        ans1 = [(x, y)]
        p = x + 2
        for i in range(b - 1):
            ans1.append((p, y))
            right.append((p + 1, y))
            ans.append((p, y - 1))
            ans.append((p, y + 1))
            p += 2

        print("YES")
        for i in ans1:
            print(*i)
        for i in right:
            print(*i)
        for i in range(w - len(right)):
            print(*ans[i])
        # print(len(ans), w)


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
