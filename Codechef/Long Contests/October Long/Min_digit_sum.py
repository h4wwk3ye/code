
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
        self.parent = None
        self.depth = 0


class Binary_tree:
    def __init__(self):
        self.root = None

    def add_root(self, val):
        root_node = Node(val)
        self.root = root_node

    def add_left(self, node, value):
        new_node = Node(value)
        node.left = new_node

    def add_right(self, node, value):
        new_node = Node(value)
        node.right = new_node


def sum_digits(n):
    r = 0
    while n:
        r, n = r+n % 10, n//10
    return r


if __name__ == '__main__':
    for t in range(int(input())):
        n, D = map(int, input().split())
        tree = Binary_tree()
        tree.add_root(n)
        queue = []
        d = {}
        queue.append(tree.root)
        d[tree.root.data] = tree.root.depth
        minimum = []
        minimum.append([tree.root.data, tree.root.depth])
        while queue:
            node = queue.pop(0)
            digit_sum = sum_digits(node.data)
            if digit_sum not in d:
                left_node = Node(digit_sum)
                node.left = left_node
                queue.append(node.left)
                d[node.left.data] = node.depth+1
                node.left.depth = node.depth+1
                if digit_sum < minimum[0][0]:
                    minimum.pop()
                    minimum.append([digit_sum, node.left.depth])
            new_n = node.data+D
            if new_n > tree.root.data+11*D:
                break
            if new_n not in d:
                right_node = Node(new_n)
                node.right = right_node
                queue.append(node.right)
                d[node.right.data] = node.depth+1
                node.right.depth = node.depth+1
                if new_n < minimum[0][0]:
                    minimum.pop()
                    minimum.append([new_n, node.right.depth])
            '''for _ in range(len(queue)):
                print(queue[_].data, end=' ')
                print()'''

            # print(d)
        print(minimum[0][0], minimum[0][1])
