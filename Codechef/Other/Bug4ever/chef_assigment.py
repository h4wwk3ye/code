#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <05/Oct/2019 11:42:27 AM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    for tc in range(int(input())):
        inp = input().split()
        d = {}
        first = {}
        mx = -1
        cnt = 0
        j = 0
        for i in inp:
            if i not in d:
                d[i] = 0
            d[i] += 1
            cnt += len(i)
            first[i] = j
            if mx == -1:
                mx = [d[i], i]
            else:
                if d[i] > mx[0]:
                    mx = [d[i], i]
                elif d[i] == mx[0] and first[i] < first[mx[1]]:
                    mx = [d[i], i]
            j += 1

        # print(d)
        for _ in range(int(input())):
            p = input()
            x = p.split()
            if x[0] == "1":
                i = x[1]
                cnt += len(i)
                d[i] += 1
                first[i] = j
                if d[i] > mx[0]:
                    mx = [d[i], i]
                elif d[i] == mx[0] and first[i] <= first[mx[1]]:
                    mx = [d[i], i]
            elif x[0] == "2":
                print(mx[1])
            else:
                print(cnt)
            j += 1
        # print(d)
        # print(first)


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
