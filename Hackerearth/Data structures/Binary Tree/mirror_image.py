class Node:
    def __init__(self, val, parent_value):
        self.data = val
        self.parent_value = parent_value
        self.left = None
        self.right = None


class Binary_tree:
    def __init__(self):
        self.root = None

    def find_parent(self, node, key):

        if not node:
            return
        if node.data == key:
            return node
        if node.left:
            self.find_parent(node.left, key)
        if node.right:
            self.find_parent(node.right, key)

    def create_root(self, key):
        self.root = Node(key, -1)

    def insert_left(self, node, key, parent_key):
        node.left = Node(key, parent_key)

    def insert_right(self, node, key, parent_key):
        node.right = Node(key, parent_key)

    def preOrder(self):
        current = self.root
        if not root:
            return
        print(current.data)
        preOrder(current.left)
        preOrder(current.right)


if __name__ == '__main__':
    tree = Binary_tree()
    N, Q = map(int, input().split())
    tree.create_root(1)
    for i in range(N-1):
        inp = list(input().split())
        if inp[2] == 'L':
            node = tree.find_parent(tree.root, int(inp[0]))
            tree.insert_left(node, int(inp[1]), int(inp[0]))
        else:
            node = tree.find_parent(tree.root, int(inp[0]))
            tree.insert_right(node, int(inp[1]), int(inp[0]))
    tree.preOrder()
