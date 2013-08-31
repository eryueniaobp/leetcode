class Solution {
    vector<vector<int> > _ret;
    vector<int> comb;
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        _ret.clear();
        comb.clear();
        dfs(n,k,0,0);
        return _ret;
    }
    void dfs(int n,int k,int l,int s){
        if(l == k ){
            _ret.push_back(comb);
            return;
        }
        for(int i = s ; i< n ;i++){
            comb.push_back(i+1);
            dfs(n,k,l+1,i+1);
            comb.pop_back();
        }
    }
};


