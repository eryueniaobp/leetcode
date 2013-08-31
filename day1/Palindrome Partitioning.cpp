class Solution {
    vector<vector<string>> retVString;
    bool palin[1500][1500];
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() == 0)
            return vector<vector<string>>();
        int leng = s.size();
        for(int i = 0; i < leng; i++)
            for(int j = 0; j < leng; j++)
                palin[i][j] = false;

        for(int i = leng-1; i >= 0; i--){
            for(int j = i; j < leng; j++){
                if(s[i] == s[j] && (j-i<2 || palin[i+1][j-1])){
                    palin[i][j] = true;
                }
            }
        }
        retVString.clear();
        dfs(s, 0, vector<string>());
        return retVString; 
    }
    void dfs (string& s, int start, vector<string> palinStr)
    {
        if(start == s.size())
        {
            retVString.push_back(palinStr);
        }
        for(int i = start; i < s.size(); i++)
        {
            if(palin[start][i])
            {
                palinStr.push_back(s.substr(start, i - start + 1));
                dfs(s, i+1, palinStr);
                palinStr.pop_back();
            }
        }
    }
};

