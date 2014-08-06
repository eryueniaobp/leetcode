/**
 * DFS 
 */
class Solution {
private:
    vector<string> ret;
public:
    void solve(int dep, int maxDep, int leftNum, int leftNumTotal, string s) {
        if (leftNumTotal * 2 > maxDep)
            return;

        if (dep == maxDep){
            ret.push_back(s);
            return;
        }
        solve(dep + 1, maxDep, leftNum + 1, leftNumTotal + 1, s + '(');
        if (leftNum > 0)
            solve(dep + 1, maxDep, leftNum - 1, leftNumTotal, s + ')');
    }

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        solve(0, 2 * n, 0, 0, "");
        return ret;
    }  
};

