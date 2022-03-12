class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Binary_Search_Tree:
    def __init__(self):
        self.root = None

    def insert(self, root, val):
        if not self.root:
            self.root = Node(val)
        else:
            self._insert(root, val)

    def _insert(self, root, val):
        if val < root.data:
            if root.left:
                self._insert(root.left, val)
            else:
                root.left = Node(val)
        else:
            if root.right:
                self._insert(root.right, val)
            else:
                root.right = Node(val)


n = int(input())
array_tree = [-1, 1]
tree = Binary_Search_Tree()
tree.insert(tree.root, 1)
for i in range(n):
    a, b = map(int, input().split())
    if a != -1:
        tree.insert(tree.root, a)
    if b != -1:
        tree.insert(tree.root, b)

t = int(input())
