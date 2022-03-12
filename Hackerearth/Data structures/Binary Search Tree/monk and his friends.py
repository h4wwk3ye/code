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

    def find(self, root, val):
        if not root:
            return False
        if root.data == val:
            return True
        if val < root.data:
            return self.find(root.left, val)
        else:
            return self.find(root.right, val)


for _ in range(int(input())):
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    present_students = arr[:n]
    future_students = arr[n:]
    tree = Binary_Search_Tree()
    for element in present_students:
        tree.insert(tree.root, element)
    for element in future_students:
        if tree.find(tree.root, element):
            print('YES')
        else:
            print('NO')
