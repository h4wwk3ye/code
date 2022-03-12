#	!/bin/env python3
#	encoding: UTF-8
#	Modified: <01/Jan/2019 12:32:34 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
from collections import defaultdict

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def bfs(tree, level, root, n):
    from collections import deque
    queue = deque()
    level[1] = 1
    queue.append(root)
    visited = [False] * (n + 1)
    visited[1] = True
    while len(queue) != 0:
        pop = queue.popleft()
        for neighbours in tree[pop]:
            if visited[neighbours] == False:
                level[neighbours] = 1 + level[pop]
                queue.append(neighbours)
                visited[neighbours] = True


def main():
    n = int(input())
    tree = {i: [] for i in range(1, n + 1)}
    for i in range(n - 1):
        a, b = get_ints()
        tree[a].append(b)
        tree[b].append(a)
    level = [0] * (n + 1)
    bfs(tree, level, 1, n)
    x = int(input())
    print(level.count(x))


if __name__ == "__main__":
    main()
