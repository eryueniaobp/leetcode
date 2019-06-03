class Excel:

    def __init__(self, H: int, W: str):
        from collections import defaultdict
        self.matrix = defaultdict(int)
        self.formula = defaultdict(list)
        
        self.myformula = defaultdict(list)

    def update(self, r,c):
        if (r, c) in self.myformula:
            cells = self.myformula.pop((r,c))
            for x, y in cells:
                self.formula[x, y].remove((r,c))
    def set(self, r: int, c: str, v: int) -> None:
        self.update(r,c)
        gap  = v - self.matrix[r,c] 
        self.matrix[r,c] = v 
        
        def do(r, c):
            
            if (r, c) in self.formula:
                cells  = self.formula[r,c ]   # r, c -> cells 
                for x, y  in cells:
                    self.matrix[x, y] += gap 
                    do(x, y)
        do(r, c )      
        

    def get(self, r: int, c: str) -> int:
        return self.matrix[r,c]
        

    def sum(self, r: int, c: str, strs: List[str]) -> int:
        """
        update formula firstly ! 
        """
        
        self.update(r,c)
        ret = 0 
        for cell in strs:
            if ':' in cell:
                i = cell.index(':')
                r1, c1 = int(cell[:i][1:]), cell[:i][0]
                r2, c2 = int(cell[i+1:][1:]), cell[i+1:][0]
                for i in range(r1, r2+1):
                    j = c1 
                    while j <= c2:
                        self.formula[i,j].append((r,c))
                        self.myformula[r,c].append((i,j)) 
                        ret += self.matrix[i, j]
                        j = chr(ord(j) + 1 )
                pass 
            else:
                self.formula[int(cell[1:]), cell[0]].append( (r,c)) 
                
                self.myformula[r,c].append((int(cell[1:]), cell[0])) 
                
                ret += self.matrix[int(cell[1:]), cell[0]]
                
        self.matrix[r,c] = ret 
        return ret 
        


# Your Excel object will be instantiated and called as such:
# obj = Excel(H, W)
# obj.set(r,c,v)
# param_2 = obj.get(r,c)
# param_3 = obj.sum(r,c,strs)
