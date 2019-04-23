class Solution:
    def prefix(self, needle):
        buf = [0] * len(needle)
        lenn = len(needle) 
        
        
        for i in range(lenn):
            if i == 0: 
                pass 
            else:
                if needle[i] == needle[ buf[i-1]]:
                    buf[i] = buf[i-1] +1 
                else:
                    # 这里采用穷举法 来查找当前位置的  前缀..
                    k = buf[i-1]
                    while k > 0:
                        if needle[:k] == needle[i-k+1:i+1]:
                            break
                        else:
                            k -= 1
                    if k > 0: buf[i] = k
                    else:
                        buf[i] = 0
        for i in range(lenn-1, 0, -1):
            buf[i] = buf[i-1]
            
        buf[0] = -1 
            
            
        # remove 
        
        
        
        return buf 
        
    def strStr(self, haystack: str, needle: str) -> int:
        """
        难点在于构造 prefix table.  有了这个prefix table,后续就好办了. 
        """
        if len(needle) == 0: return 0 
        if len(haystack) == 0: return -1 
        pbuf = self.prefix(needle)
        i = 0 
        lenh = len(haystack) 
        lenn = len(needle)
        j = 0 
        hit = False
        while i < lenh:
            
            while i < lenh  and j < lenn and haystack[i] == needle[j]:
                i += 1 
                j += 1
            if j < lenn:
                if j == 0: 
                    # j += 1 
                    i += 1 
                else:
                    j = pbuf[j]
            else:
                hit = True 
                break 
        if hit:       return i - lenn 
        return -1 
            
        
        
            
        
        
