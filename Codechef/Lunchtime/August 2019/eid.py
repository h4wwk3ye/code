#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <31/Aug/2019 08:04:49 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import os
import sys
from io import BytesIO, IOBase


def main():
    for tc in range(int(input())):
        a1, a2, a3, c1, c2, c3 = get_ints()
        arr = [(a1, c1), (a2, c2), (a3, c3)]
        arr.sort()
        ans = "FAIR"
        if arr[0][0] == arr[1][0]:
            if arr[0][1] != arr[1][1]:
                ans = "NOT FAIR"
        else:
            if arr[0][1] >= arr[1][1]:
                ans = "NOT FAIR"

        if arr[1][0] == arr[2][0]:
            if arr[1][1] != arr[2][1]:
                ans = "NOT FAIR"
        else:
            if arr[1][1] >= arr[2][1]:
                ans = "NOT FAIR"
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
