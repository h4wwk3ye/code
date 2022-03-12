def check_parent(array_2d, array_parent, child_index, parent_index):
    if array_2d[child_index][parent_index] == True:
        return True
    if array_parent[child_index] == -1:
        return None
    if parent_index == array_parent[child_index]:
        return True
    return check_parent(array_2d, array_parent, array_parent[child_index], parent_index)


def pre_calculate(array_parent, array_2d, n):
    for i in range(n):
        for j in range(n):
            if i > j:
                if not array_2d[i][j]:
                    array_2d[i][j] = check_parent(array_2d, array_parent, i, j)


n, k = map(int, input().split())
array_tree = list(map(int, input().split()))
arr = list(map(int, input().split()))
array_parent = [-1]
for element in arr:
    array_parent.append(element-1)
# print(array_parent)
count = 0
array_2d = [[None for i in range(n)]for j in range(n)]
pre_calculate(array_parent, array_2d, n)
# print(array_2d)
for i in range(0, n):
    for j in range(i+1, n):
        if array_2d[j][i] == True:
            for l in range(j+1, n):
                if array_2d[l][i] == True:
                    if array_tree[i]+array_tree[j]+array_tree[l] >= k:
                        count += 1
print(count)
