
from collections import defaultdict
class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        ret = []
        
        uf = defaultdict(int)  # item -> groupId 
        parent = defaultdict(int)  # groupId - > parentId
        
        self.groupSize = 0 
        def find(x,  y):
            """
            return root id 
            """
            if uf[x, y] == 0:
                return -1
            else:
                gid = uf[x, y] 
                while gid != parent[gid]:
                    gid = parent[gid]
                uf[x,y ] = gid 
                return gid 
        def addPoint(x, y , idx):
            uf[x, y] = parent[idx]  # idx is root ! 
        def create(x, y ): # create new group! 
            gid = len(uf)  + 1  
            uf[x, y] = gid 
            parent[gid] = gid 
            
            self.groupSize  += 1 
            return gid
            
        def merge(gs):
            """
            merge all gids ! 
            """
            if len(gs) == 1 : 
                return list(gs)[0]
            else:
                gs = sorted(list(gs))
                for gid in gs:
                    parent[gid] = parent[gs[0]] #min gid 
                self.groupSize -= len(gs) -1 
                return parent[gs[0]]
            
            
            
        def countGroup():
            return self.groupSize  
     
            
            
        for x, y in positions:
            idx = -1 
            gs = set()
            for dx , dy in [(0, 0) , (0,1), (0,-1),(1,0),(-1,0)]:
                if x + dx >= 0 and x+dx < m and y+dy >=0 and y+dy < n:
                    idx = find(x+dx , y+dy)
                    if idx > 0:
                        gs.add(idx)
            if len(gs) > 0:
                # merge the groups 
                idx = merge(gs)
                addPoint(x, y , idx)
            else:
                # create new group! 
                create(x, y )
                
            ret.append(countGroup())
                    
        return ret
                        
            
        
