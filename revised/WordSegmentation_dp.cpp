// lintcode tle. improve more
class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordSegmentation(string str, unordered_set<string> &dict) {
        // write your code here
        int size = str.size();
        vector<int> dp(size+1, -1);
        dp[0] = 0;
        vector<string > res(size+1);
        for(int i = 0; i < size; ++i)
        {
            if(dp[i] != -1)
            {
                for(int j = i+1; j <= size; ++j)
                {
                    const int len = j-i;
                    string substr = str.substr(i, len);
                    if(dict.find(substr) != dict.end())
                    {
                        // string space = i?" ":"";
                       // res[i+len] = res[i] + space + substr;
                        dp[i+len] = 1;
                    }
                }
            }
        }
        return dp[size] != -1 ;
    }
};

