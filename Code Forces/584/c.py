#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <15/Sep/2019 12:59:22 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    for tc in range(int(input())):
        n = int(input())
        d = input()
        arr = [0] * n
        for i in range(n):
            arr[i] = int(d[i])
        ans = 0
        for x in range(1, 11):
            f = 0
            one, two, o, t = [], [], [], []
            chk = [1] * n
            for i in range(n):
                if arr[i] > x:
                    f = 1
                if arr[i] < x:
                    one.append(arr[i])
                    o.append(arr[i])
                    chk[i] = 1
                elif arr[i] > x:
                    two.append(arr[i])
                    t.append(arr[i])
                    chk[i] = 2
                else:
                    if f == 1:
                        one.append(arr[i])
                        o.append(arr[i])
                        chk[i] = 1
                    else:
                        two.append(arr[i])
                        t.append(arr[i])
                        chk[i] = 2
            one.sort()
            two.sort()

            if one == o and two == t:
                if len(one) == 0 or len(two) == 0:
                    ans = 1
                elif one[-1] <= two[0]:
                    ans = 1
            if ans == 1:
                print(*chk, sep="")
                break

        if ans == 0:
            print("-")


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
