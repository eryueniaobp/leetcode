/**
 * O(n^2) 动态规划
 */
class Solution {
private:
    bool f[1000][1000];
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        if (s1.size() + s2.size() != s3.size())
            return false;
            
        f[0][0] = true;
        for(int i = 1; i <= s1.size(); i++)
            f[i][0] = f[i-1][0] && (s3[i-1] == s1[i-1]);
            
        for(int j = 1; j <= s2.size(); j++)
            f[0][j] = f[0][j-1] && (s3[j-1] == s2[j-1]);
            
        for(int i = 1; i <= s1.size(); i++)
            for(int j = 1; j <= s2.size(); j++)
                f[i][j] = (f[i][j-1] && s2[j-1] == s3[i+j-1]) || (f[i-1][j] && s1[i-1] == s3[i+j-1]);
                
        return f[s1.size()][s2.size()];
    }
};

