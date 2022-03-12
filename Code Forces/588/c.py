#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <25/Sep/2019 02:37:23 AM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    n, m = get_ints()
    # graph = {i: [] for i in range(n + 1)}
    edges = []
    deg = [0] * (n + 1)
    for _ in range(m):
        u, v = get_ints()
        # graph[u].append(v)
        # graph[v].append(u)
        edges.append([u, v])
        edges.append([v, u])
        deg[u] += 1
        deg[v] += 1
    tmp = []
    if m == 0:
        print(0)
        return
    for i in range(1, n + 1):
        tmp.append([deg[i], i])

    tmp.sort(reverse=True)

    curr = [[6, 1], [5, 2], [4, 3], [3, 4], [2, 5], [1, 6]]

    completed = {}
    # print(tmp)
    cant_use = {i: [] for i in range(n + 1)}
    used = {}
    ans = 0
    while True:
        f = 1
        for i in curr:
            if i[0] > 0:
                f = 0
        if f == 1:
            break
        if len(tmp) == 0:
            break
        # for i in range(len(tmp)):
        idx = 0

        if len(cant_use[tmp[0][1]]) == 6:
            tmp.pop(0)
            continue

        while True:
            if idx == 6:
                break
            if curr[idx][1] in cant_use[tmp[0][1]]:
                idx += 1
            else:
                break
        if idx == 6:
            tmp.pop(0)
            continue

        ans += min(curr[idx][0], tmp[0][0])
        # print(curr[idx][0], tmp[0][0], tmp[0][1])
        if curr[idx][0] <= tmp[0][0]:
            ans -= 1

        # curr[0][0] -= min(curr[idx][0], deg[tmp[0][0]])
        cnt = min(curr[idx][0], tmp[0][0])
        curr[idx][0] = 0
        tmp[0][0] -= min(curr[idx][0], tmp[0][0])
        for j in range(1, n + 1):
            if [j, tmp[0][1]] in edges and j not in completed:
                for k in range(len(tmp)):
                    if tmp[k][1] == j:
                        tmp[k][0] -= 1
                        cant_use[tmp[k][1]].append(curr[idx][1])

        for i in range(tmp[0][1], n + 1):
            if cnt == 0:
                break
            used[i] = 1
            cnt -= 1

        completed[tmp[0][1]] = idx
        # print(ans, tmp[0][1], cant_use[tmp[0][1]])
        # ans -= len(cant_use[tmp[0][1]])

        tmp.pop(0)
        curr.sort(reverse=True)
        tmp.sort(reverse=True)
        # print(tmp)
        # print(curr)
        # print(ans, idx)
        # print(cant_use)
    # print(completed)

    print(min(m, ans + n - len(completed)))


"""
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

"""


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def get_ints():
    return map(int, sys.stdin.readline().split())


def input():
    return sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
