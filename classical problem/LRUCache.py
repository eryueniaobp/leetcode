#encoding=utf-8


class Node:
    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None


class LRUCache:

    def __init__(self, capacity: int):
        self.head = None
        self.tail = None
        self.k2idx = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.k2idx:
            return -1
        else:
            node = self.k2idx[key]
            value = node.value
            self._remove(node)
            self._add(node)
            return value

    def _add(self, node: Node) -> None:

        if self.head == None:
            assert self.tail == None
            self.head = self.tail = node
            node.next = None
            node.prev = None
        else:
            node.next = None
            node.prev = self.tail
            self.tail.next = node
            self.tail = self.tail.next

    def _remove(self, node: Node) -> None:
        """
        remove the current node!!
        note: update head and tail if necessary.
        """
        assert self.head != None
        if self.head == self.tail:  # only one!!
            self.head = None
            self.tail = None
            return
            # has >= 2 nodes!
        if self.head == node:
            self.head = self.head.next
            self.head.prev = None
        elif self.tail == node:
            self.tail = self.tail.prev
            self.tail.next = None
        else:
            node.prev.next = node.next
            node.next.prev = node.prev

    def put(self, key: int, value: int) -> None:
        if len(self.k2idx) == self.capacity:
            if key not in self.k2idx:
                # invalidate the least recently used
                assert self.head != None
                self.k2idx.pop(self.head.key) # remove the Node !!!
                self._remove(self.head)

        if key in self.k2idx:
            node = self.k2idx[key]
            self._remove(node)

        node = Node(key, value)
        self._add(node)
        self.k2idx[key] = node

    def show(self) -> None:
        node = self.head
        s = []
        if node == None: s += ['None']
        while node != None:
            s += [str(node.value)]
            node = node.next
        return '->'.join(s)


# Your LRUCache object will be instantiated and called as such:
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
obj = LRUCache(2)
obj.put(1,1)
obj.put(2,2)
obj.get(1)


print ( 'link = ' ,obj.show())
obj.put(3,3)


print ( 'link = ' ,obj.show())

obj.get(2)

print ( 'link = ' , obj.show())
obj.put(4,4)

print ( 'link = ' , obj.show())
obj.get(1)
print ( 'link = ' , obj.show())
obj.get(3)
print ( 'link = ' , obj.show())


obj.get(4)
print ( 'link = ' , obj.show())



