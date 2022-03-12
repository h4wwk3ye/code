class Node:
    def __init__(self, value):
        self.data = value
        self.next = None


class Linked_list:
    def __init__(self):
        self.head = None
        self.tail = None

    def empty(self):
        self.head = None
        self.tail = None

    def create(self, array):
        for element in array:
            if self.head == None:
                self.head = Node(element)
                self.tail = self.head
            else:
                current = self.tail
                new_node = Node(element)
                current.next = new_node
                self.tail = new_node

    def delete(self):
        current = self.head
        if not current.next:
            self.head = None
            self.tail = None
            return
        if current.data < current.next.data:
            self.head = current.next
            return

        while True:
            if current.next.next and current.next:
                if current.next.data < current.next.next.data:
                    current.next = current.next.next
                    break
                current = current.next

            elif not current.next.next:
                current.next = None
                self.tail = current
                break

    def prnt(self):  # def __str__(self) can be used by calling l_list in main
        current = self.head
        string = []
        while current:
            string.append(current.data)
            current = current.next
        return string


for _ in range(int(input())):
    n, k = map(int, input().split())
    popularity = list(map(int, input().split()))
    l_list = Linked_list()
    l_list.empty()
    l_list.create(popularity)
    count = 0
    string = []
    while count != k:
        l_list.delete()
        count += 1
    string = l_list.prnt()
    print(*string)
