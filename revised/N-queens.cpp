/**
 * DFS 即可
 */
class Solution {
private:
    vector<vector<string> > ret;
    int a[100];
    bool canUse[100];
public:
    bool check(int y, int n)
    {
        for(int i = 0; i < n; i++)
            if (abs(i - n) == abs(y - a[i]))
                return false;
        return true;
    }
    
    void solve(int dep, int maxDep)
    {
        if (dep == maxDep)
        {
            vector<string> ans;
            for(int i = 0; i < maxDep; i++)
            {
                string s;
                for(int j = 0; j < a[i]; j++)
                    s += '.';
                s += 'Q';
                for(int j = 0; j < maxDep - (a[i] + 1); j++)
                    s += '.';
                ans.push_back(s);
            }
            ret.push_back(ans);
            
            return;
        }
        
        for(int i = 0; i < maxDep; i++)
            if (canUse[i] && check(i, dep))
            {
                canUse[i] = false;
                a[dep] = i;
                solve(dep + 1, maxDep);
                canUse[i] = true;             
            }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        memset(canUse, true, sizeof(canUse));
        solve(0, n);
        return ret;
    }
};

