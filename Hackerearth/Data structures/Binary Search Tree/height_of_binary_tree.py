import sys
sys.setrecursionlimit(2000)


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

    def height(self, root):
        current = root
        if not current:
            return 0
        return 1+max(self.height(root.left), self.height(root.right))

    def preOrder(self, root):
        current = root
        if not current:
            return

        print(current.data)
        self.preOrder(root.left)
        self.preOrder(root.right)


n = int(input())
array = list(map(int, input().split()))
tree = Binary_Search_Tree()
for element in array:
    tree.insert(tree.root, element)
print(tree.height(tree.root))
# tree.preOrder(tree.root)
