#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <09/Jun/2019 08:51:51 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    n = int(input())
    arr = get_array()
    di = {}
    for i in range(n):
        if arr[i] not in di:
            di[arr[i]] = []
        di[arr[i]].append(i)
    chk = [4, 8, 15, 16, 23, 42]
    for i in chk:
        if i not in di:
            print(n)
            return
    # print(di)
    a, b, c, d, e, f = 0, 0, 0, 0, 0, 0
    #print(a, b, c, d, e, f)
    ans = 0
    while True:
        if a >= len(di[4]) or b >= len(di[8]) or c >= len(di[15]) or d >= len(di[16]) or e >= len(di[23]) or f >= len(di[42]):
            break
        curr = b
        while curr < len(di[8]) and di[4][a] > di[8][curr]:
            curr += 1
        if curr == len(di[8]):
            break
        a += 1
        b = curr
        curr = c
        while curr < len(di[15]) and di[8][b] > di[15][curr]:
            curr += 1
        if curr == len(di[15]):
            break
        b += 1
        c = curr
        curr = d
        while curr < len(di[16]) and di[15][c] > di[16][curr]:
            curr += 1
        if curr == len(di[16]):
            break
        c += 1
        d = curr
        curr = e
        while curr < len(di[23]) and di[16][d] > di[23][curr]:
            curr += 1
        if curr == len(di[23]):
            break
        d += 1
        e = curr
        curr = f
        while curr < len(di[42]) and di[23][e] > di[42][curr]:
            curr += 1
        if curr == len(di[42]):
            break
        e += 1
        f = curr + 1
        ans += 6
    print(n - ans)


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
        if py2:
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
