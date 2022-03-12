def union(i, j):
    id_i = find(i)
    id_j = find(j)
    if id_i == id_j:  # if they are already in same set
        return
    if rank[id_i] > rank[id_j]:
        parent[id_j] = parent[id_i]
        size[id_i] += size[id_j]
    else:
        parent[id_i] = parent[id_j]
        size[id_j] += size[id_i]
        if rank[id_i] == rank[id_j]:
            rank[id_j] += 1


def find(i):
    if i != parent[i]:
        parent[i] = find(parent[i])  # path compression
    return parent[i]


n, q = map(int, input().split())
parent = [None]*(n+1)
rank = [None]*(n+1)
size = [1]*(n+1)
for i in range(n+1):
    parent[i] = i
    rank[i] = 0
for _ in range(q):
    inp = input().split()
    if inp[0] == 'M':
        i = int(inp[1])
        j = int(inp[2])
        union(i, j)
    elif inp[0] == 'Q':
        check = int(inp[1])
        index = find(check)
        print(size[index])
