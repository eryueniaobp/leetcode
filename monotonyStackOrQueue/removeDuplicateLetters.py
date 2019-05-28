"""
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Natural but smart solution .
"""
from collections import defaultdict
class Solution:
    
    def removeDuplicateLetters(self, s: str) -> str:
        cntmap = defaultdict(int)
        visited = defaultdict(int)
        for c in s:
            cntmap[c] = cntmap[c] + 1 
        ret = ['0']
        for ch in s:
            cntmap[ch] -= 1 
            if visited[ch] == 0:
                while ch < ret[-1] and cntmap[ret[-1]] > 0:
                    visited[ret[-1]] = False
                    ret.pop()
                ret.append(ch)
                visited[ch] = 1 
            else:
                pass 
        return ''.join(ret[1:])
        
