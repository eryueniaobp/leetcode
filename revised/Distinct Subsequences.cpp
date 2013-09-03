//题目： count(subsequence of S == T ) 
/*
 *动归 O(m*n)
 */
class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.size();
        int m = T.size();
        int *dp = new int[m];
        fill(dp,dp+m,0);
        for (int i = 0; i < n; ++i) {
            for (int j = m-1; j >= 0; --j) {
                if (T[j] == S[i]) {
                    if (j==0) dp[0]++;
                    else dp[j] += dp[j-1];
                }
            }
        }
        return dp[m-1];
    }
};

