/**
 * DFS 
 */
class Solution {
    vector<vector<int> > ret_;
    vector<int> comb_;
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret_.clear();
        comb_.clear();
        dfs(n,k,0,0);
        return ret_;
    }
    void dfs(int n,int k,int l,int s){
        if(l == k ){
            ret_.push_back(comb_);
            return;
        }
        for(int i = s ; i< n ;i++){
            comb_.push_back(i+1);
            dfs(n,k,l+1,i+1);
            comb_.pop_back();
        }
    }
};


