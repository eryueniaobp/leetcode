class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == '': return s
        # dp[i][j] 是否 回文 
        dp = [ [False] * len(s) for i in range(len(s))]
        
        N = len(s) 
        
        for i in range(N-1, -1 , -1):
            dp[i][i] = True 
            for j in range(i+1 , N):
                dp[i][j] = dp[i+1][j-1] and s[i] == s[j] if i+1<= j-1 else s[i] == s[j]  # transform formula .
        
        idx = 0 
        maxlen = 0
        for i in range(N):
            for j in range(i, N):
                if dp[i][j] and j-i + 1 > maxlen:
                    maxlen = j - i + 1 
                    idx = i 
        return s[idx:idx+maxlen]
