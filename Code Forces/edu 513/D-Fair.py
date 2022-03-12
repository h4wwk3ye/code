import sys


class Node:
    def __init__(self, val):
        self.value = val
        self.next = None
        self.prev = None

    def get_val(self):
        return self.value


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add_node(self, val):
        new_node = Node(val)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

    def delete_node(self, node):
        if node != self.head and node != self.tail:
            node.prev.next = node.next

        elif node == self.head:
            if node.next:
                self.head = node.next
            else:
                self.head = None
        elif node == self.tail:
            self.tail = node.prev
            node.prev.next = None


if __name__ == '__main__':
    n, t = map(int, sys.stdin.readline().split())
    _arr = list(map(int, sys.stdin.readline().split()))
    min = float('inf')
    l_list = LinkedList()
    total = 0
    length = 0
    for i in range(n):
        if _arr[i] <= t:
            l_list.add_node(_arr[i])
            if _arr[i] < min:
                min = _arr[i]
            total += _arr[i]
            length += 1

    count = 0
    if t >= total:
        x = t//total
        count += length*x
        t -= (total*x)

    flag = 1
    while t >= min and flag != 0:
        if total > 0 and t >= total:
            x = t//total
            count += length*x
            t -= (total*x)
        flag = 0
        tmp = l_list.head
        while tmp:
            if tmp.get_val() > t:
                delete = tmp
                tmp = tmp.next
                l_list.delete_node(delete)
                total -= delete.get_val()
                length -= 1
            else:
                check = 0
                count += 1
                t -= tmp.get_val()
                if t < tmp.get_val():
                    delete = tmp
                    tmp = tmp.next
                    l_list.delete_node(delete)
                    total -= delete.get_val()
                    length -= 1
                    check = 1
                flag = 1
                if check == 0:
                    tmp = tmp.next

    print(count)
