#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <21/Sep/2019 02:31:07 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    N = 10 ** 9 + 5
    arr = []
    i = 1
    x = 0
    org = ""
    t = ""

    for i in range(1, 31):
        t += str(i)
        org += t

    print(len(org))

    while x < N:
        x = 2 * x + len(str(i))
        arr.append([x, i])
        i += 1
    print(arr)
    for tc in range(int(input())):
        n = int(input())
        if n == 1:
            print(1)
            continue
        x = 0
        ans = -1
        f = 0
        for i in arr:
            if i[0] >= n:
                x = i[1]
                f = i[0]
                if i[0] == n:
                    ans = 1
                break

        if ans != -1:
            p = str(i[1])
            print(p[-1])
            continue
        s = 1
        for i in arr:
            if i[0] >= n:
                break
            s = i[0]
        tmp = ""
        curr = 1
        p = ""
        # print(s, f)
        for i in range(s + 1, n + 1):
            if len(tmp) >= (n - s):
                break
            p += str(curr)
            tmp += p
            curr += 1
        print(n, tmp)
        print(tmp[n - s])


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
