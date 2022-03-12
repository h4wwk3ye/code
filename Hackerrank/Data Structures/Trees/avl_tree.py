class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
        self.parent = None
        self.height = 0


class Avl_tree:
    def __init__(self):
        self.root = None

    def insert(self, val):
        current = self.root
        if not self.root:
            self.root = Node(val)
        else:
            self._insert(current, val)

    def _insert(self, root_node, val):
        if root_node.data > val:
            if root_node.left:
                self._insert(root_node.left, val)
            else:
                root_node.left = Node(val)
                root_node.left.parent = root_node
        else:
            if root_node.right:
                self._insert(root_node.right, val)
            else:
                root_node.right = Node(val)
                root_node.right.parent = root_node
        tmp = root_node
        while tmp:
            self.adjustHeight(tmp)
            tmp = tmp.parent

    def adjustHeight(self, node):
        if hasattr(node.left, 'height'):
            left_height = node.left.height
        else:
            left_height = -1
        if hasattr(node.right, 'height'):
            right_height = node.right.height
        else:
            right_height = -1
        node.height = 1+max(left_height, right_height)

    def find(self, _root, val):
        if _root.data == val:
            return _root
        elif val < _root.data:
            if _root.left:
                return self.find(_root.left, val)
        else:
            if _root.right:
                return self.find(_root.right, val)

    def rebalance(self, node):
        p = None
        if node.parent:
            p = node.parent
        if node.left and not node.right and node.left.height >= 1:
            self.rebalance_right(node)
        elif node.left and node.right and node.left.height > node.right.height+1:
            self.rebalance_right(node)
        if node.right and not node.left and node.right.height >= 1:
            self.rebalance_left(node)
        elif node.left and node.right and node.right.height > node.left.height+1:
            self.rebalance_left(node)
        self.adjustHeight(node)
        if p:
            self.rebalance(p)

    def rebalance_left(self, node):
        new_root = node.right
        if new_root.left and not new_root.right:  # only left child of right chidl
            self.rotate_right(new_root)
        # height of left grand child is more than right grand child (children of right child)
        if (new_root.left and new_root.right) and (new_root.left.height > new_root.right.height):
            self.rotate_right(new_root)
        self.rotate_left(node)

    def rotate_left(self, node):
        child = node.right
        node.right = child.left
        if child.left:
            child.left.parent = node
        child.left = node
        child.parent = node.parent
        if node.parent:
            if node.parent.left == node:
                node.parent.left = child
            else:
                node.parent.right = child
        node.parent = child
        if self.root == node:
            self.root = child
        self.adjustHeight(node)
        self.adjustHeight(child)

    def rebalance_right(self, node):
        new_root = node.left
        if new_root.right and not new_root.left:
            self.rotate_left(new_root)
        if (new_root.right and new_root.left) and (new_root.right.height > new_root.left.height):
            self.rotate_left(new_root)
        self.rotate_right(node)

    def rotate_right(self, node):
        child = node.left
        node.left = child.right
        if child.right:
            child.right.parent = node
        child.right = node
        if node.parent:
            if node.parent.left == node:
                node.parent.left = child
            else:
                node.parent.right = child
        child.parent = node.parent
        node.parent = child
        if self.root == node:
            self.root = child
        self.adjustHeight(node)
        self.adjustHeight(child)

    def delete(self, node):
        if node.height == 0:
            if node == self.root:
                self.root = None
            else:
                if node.parent.left == node:
                    node.parent.left = None
                else:
                    node.parent.right = None
        elif not node.right:
                 # no right child of node to be deleted. Just promote left child

            if node.parent.left == node:
                node.parent.left = node.left
            else:
                node.parent.right = node.left
            if node == self.root:
                self.root = node.left
            else:
                node.left.parent = node.parent
        else:
            replacement = node.right
            while replacement.left:  # closest node to node to be deleted
                replacement = replacement.left
            replacement.left = node.left
            child = replacement.right
            if replacement.right:  # promote it in place of replacement
                replacement.parent.left = replacement.right
                replacement.right.parent = replacement.parent
            replacement.right = node.right
            m = replacement.parent  # old parent
            replacement.parent = node.parent
            if node == self.root:
                self.root = replacement
            else:
                if node.parent.left == node:
                    node.parent.left = replacement
                else:
                    node.parent.right = replacement

            if m:
                self.rebalance(m)

    def inOrder(self, root):
        if not root:
            return
        self.inOrder(root.left)
        print(root.data)
        self.inOrder(root.right)


def main():
    arr = [2, 3, 4, 89, 7, 1]
    tree = Avl_tree()
    for element in arr:
        tree.insert(element)
        node = tree.find(tree.root, element)
        tree.rebalance(node)
    tree.inOrder(tree.root)
    node_del = tree.find(tree.root, 3)
    tree.delete(node_del)
    tree.inOrder(tree.root)


main()
