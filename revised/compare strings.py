class Solution:
    """
    @param A : A string includes Upper Case letters
    @param B : A string includes Upper Case letters
    @return :  if string A contains all of the characters in B return True else return False
    """
    def compareStrings(self, A, B):
        # write your code here
        a = [ 0 ] * 26  
        
        for s in A:
            p = ord(s) - ord('A') 
            a[p] += 1 
                
        for s in B:
            p = ord(s) - ord('A') 
            a[p] -= 1
            if a[p] < 0 :
                return False
        
        return True 
            

