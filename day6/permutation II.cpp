class Solution {
    vector<vector<int> > _ret;
    vector<int> _perm;
    unordered_set<int> _set;
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        _ret.clear();
        _set.clear();
        _perm.clear();
        dfs(num,0);  
        return _ret;
    }
    void dfs(vector<int> &num ,int l){
        if( l == num.size() ) {
            _ret.push_back(_perm);
            return;
        }
        unordered_set<int> lset;
        for(int i = 0 ;i<num.size(); i ++){
            if(_set.find(i) != _set.end()) {
                continue;
            }
            if( lset.find(num[i]) != lset.end() ){
                continue;
            }
            lset.insert(num[i]); 
            _perm.push_back(num[i]);
            _set.insert(i);
            dfs(num,l+1);
            _set.erase(i);
            _perm.pop_back();
        }
        lset.clear();
    }
};


