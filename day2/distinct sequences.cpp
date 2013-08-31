//题目： count(subsequence of S == T ) 
public class Solution {
    public int numDistinct(String S, String T) {
        int n = S.length();
        int m = T.length();
        int[] dp = new int[m];
        for (int i = 0; i < n; ++i) {
            for (int j = m-1; j >= 0; --j) {
                if (T.charAt(j) == S.charAt(i)) {
                    if (j==0) dp[0]++;
                    else dp[j] += dp[j-1];
                }
            }
        }
        return dp[m-1];
    }
}

