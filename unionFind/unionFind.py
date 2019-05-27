from collections import defaultdict
class UnionFind:
    def __init__(self):
        self.parent = defaultdict(int)
        pass
    def find(self, id ):
        if id not in self.parent:
            return -1 
        p = id
        while p != self.parent[p]:
            p = self.parent[p] 
        root = p 
        p = id 
        while p != self.parent[p]:
            tmp = self.parent[p]
            self.parent[p] = root 
            p = tmp
        return root  
    def union(self, a,  b ):
        ra = self.find(a)
        if ra == -1: 
            self.parent[a] = a 
            ra = a 
        rb = self.find(b) 
        if rb == -1:
            self.parent[b] = b
            rb = b 
        self.parent[ra] = rb
    def isconnected(self, a, b ):
        ra = self.find(a)
        rb = self.find(b) 
        if ra == -1 or rb == -1: return False 
        return ra == rb 
