#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <15/Apr/2019 07:45:37 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


from __future__ import print_function
py2 = round(0.5)

if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange
    from cStringIO import StringIO as BytesIO
else:
    from io import BytesIO
    from builtins import str as __str__
    str = lambda x=b'': x if type(x) is bytes else __str__(x).encode()

import os
import sys
from io import IOBase
sys.setrecursionlimit(10**6)
import resource
resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))

# FastIO for PyPy2 and PyPy3 (works with interactive) by Pajenegod


class FastI(object):
    def __init__(self, fd=0, buffersize=2**14):
        self.stream = stream = BytesIO()
        self.bufendl = 0

        def read2buffer():
            s = os.read(fd, buffersize + os.fstat(fd).st_size)
            pos = stream.tell()
            stream.seek(0, 2)
            stream.write(s)
            stream.seek(pos)
            return s
        self.read2buffer = read2buffer

    # Read entire input
    def read(self):
        while self.read2buffer():
            pass
        return self.stream.read() if self.stream.tell() else self.stream.getvalue()

    def readline(self):
        while self.bufendl == 0:
            s = self.read2buffer()
            self.bufendl += s.count(b"\n") + (not s)
        self.bufendl -= 1
        return self.stream.readline()

    def input(self): return self.readline().rstrip(b'\r\n')

    # Read all remaining integers, type is given by optional argument, this is fast
    def readnumbers(self, zero=0):
        conv = ord if py2 else lambda x: x
        A = []
        numb = zero
        sign = 1
        i = 0
        s = self.read()
        try:
            while True:
                if s[i] >= b'0' [0]:
                    numb = 10 * numb + conv(s[i]) - 48
                elif s[i] == b'-' [0]:
                    sign = -1
                elif s[i] != b'\r' [0]:
                    A.append(sign * numb)
                    numb = zero
                    sign = 1
                i += 1
        except:
            pass
        if s and s[-1] >= b'0' [0]:
            A.append(sign * numb)
        return A


class FastO(IOBase):
    def __init__(self, fd=1):
        stream = BytesIO()
        self.flush = lambda: os.write(
            1, stream.getvalue()) and not stream.truncate(0) and stream.seek(0)
        self.write = stream.write if py2 else lambda s: stream.write(s.encode())


sys.stdin, sys.stdout = FastI(), FastO()
input = sys.stdin.input


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())

# ///==========MAIN=============///


def dfs_o(node, p):
    for to in graph[node]:
        if to == p:
            continue
        parent[to] = node
        dfs_o(to, node)


def dfs(node, p):
    global n, q, graph, weight, parent, v, k, vl, xl, mx, vertex
    curr = weight[node - 1] ^ k
    if (curr > mx):
        mx = curr
        vertex = node
    elif (curr == mx and node < vertex):
        vertex = node
    for to in graph[node]:
        if to == parent[node]:
            continue
        if to == p:
            continue
        dfs(to, node)


for tc in range(int(input())):
    global n, q, graph, weight, parent, v, k, vl, xl, mx, curr, vertex
    n, q = get_ints()
    graph = [[] for _ in range(n + 1)]
    weight = get_array()
    for i in range(n - 1):
        u, vi = get_ints()
        graph[u].append(vi)
        graph[vi].append(u)
    parent = [0] * (n + 1)
    dfs_o(1, 1)

    xl, vl = 0, 0
    d = {}
    for _ in range(q):
        a, b = get_ints()
        v = a ^ vl
        k = b ^ xl
        curr = 0
        mx = -1
        vertex = -1
        if (v, k) in d:
            vl = d[(v, k)][0]
            xl = d[(v, k)][1]
            print(vl, xl)
            continue
        dfs(v, v)
        d[(v, k)] = (vertex, mx)
        print(vertex, mx)
        vl = vertex
        xl = mx
