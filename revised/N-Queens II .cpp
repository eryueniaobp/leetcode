/**
 * DFS
 */
class Solution {
private:
    int ret;
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
            ret++;            
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
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = 0;
        memset(canUse, true, sizeof(canUse));
        solve(0, n);
        return ret;
    }
};

