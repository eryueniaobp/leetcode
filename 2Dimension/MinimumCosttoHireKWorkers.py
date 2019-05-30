import heapq
class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        """
        workers 
        Solution: 
            dp[K] = dp
        
        """
        h = []
        wq = list(zip(wage, quality))
        wq = sorted(wq, key=lambda x : x[0]/x[1])
        
        ret = float('inf') 
        
        sumq = 0
        for w, q in wq:
            heapq.heappush(h, (-q, w)) # get max q! 
            sumq += q 
            if len(h) == K:
                ret = min(ret, w/q * sumq)  
                
                q1, _ = heapq.heappop(h)
                q1 = -q1 
                
                sumq -= q1 
                
        return ret
                
            
                
            
            
            
        
        
        
        
