class Solution {
    vector<vector<int> > _ret;
    vector<int> _perm;
    unordered_set<int> _set;
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        _ret.clear();
        dfs(num,0);  
        return _ret;
    }
    void dfs(vector<int> &num ,int l){
        if( l == num.size() ) {
            _ret.push_back(_perm);
            return;
        }
        for(int i = 0 ;i<num.size(); i ++){
            if(_set.find(num[i]) != _set.end()) {
                continue;
            }
            _perm.push_back(num[i]);
            _set.insert(num[i]);
            dfs(num,l+1);
            _set.erase(num[i]);
            _perm.pop_back();
        }
    }
};

