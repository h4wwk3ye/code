#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <28/Sep/2019 08:47:06 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    for tc in range(int(input())):
        n, Q = get_ints()
        b = get_array()
        pref_odd = [0] * n
        pref_odd[0] = b[0]
        for i in range(2, n - 1, 2):
            pref_odd[i] = pref_odd[i - 2] + b[i]

        pref_even = [0] * n
        pref_even[1] = b[1]
        for i in range(3, n - 1, 2):
            pref_even[i] = pref_even[i - 2] + b[i]
        # print(pref_even, pref_odd)

        for _ in range(Q):
            p, q = get_ints()
            if p > q:
                p, q = q, p
            if p % 2 == q % 2:
                print("UNKNOWN")
            else:
                # f = 0
                # ans = 0
                # for j in range(q - 2, p - 2, -1):
                #     # print(b[j])
                #     if f == 0:
                #         ans += b[j]
                #     else:
                #         ans -= b[j]
                #     f = 1 ^ f
                ans = 0
                if q % 2 == 1:
                    ans += pref_even[q - 2]
                    # print(ans)
                    if p - 3 >= 0:
                        ans -= pref_even[p - 3]
                    # print(ans)
                    if q - 3 >= 0:
                        ans -= pref_odd[q - 3]
                    # print(ans)
                    if p - 2 >= 0:
                        ans += pref_odd[p - 2]
                    # print(ans)
                else:
                    ans += pref_odd[q - 2]
                    # print(ans)
                    if p - 3 >= 0:
                        ans -= pref_odd[p - 3]
                    # print(ans)
                    if q - 3 >= 0:
                        ans -= pref_even[q - 3]
                    # print(ans)
                    if p - 2 >= 0:
                        ans += pref_even[p - 2]
                    # print(ans)
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
