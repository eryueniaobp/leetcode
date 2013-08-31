class Solution {
    int _size;
    vector<vector<int> > _ret;
    vector<int> _set;
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        _size = S.size();
        sort(S.begin(),S.end(),less<int>());
        _ret.clear();
        _set.clear();
        dfs(S,0);  
        return _ret;
    }
    void dfs(vector<int> &S, int l){
        if(l == _size ){
            _ret.push_back(_set);
            return;
        }
        for(int i =  l ; i<=_size ;i++){
            if(i > l && i<_size &&  S[i] == S[i-1] ) {
                continue;
            }
            if(i<_size){
                _set.push_back(S[i]);
                dfs(S,i+1);
                _set.pop_back();
            }else{
                _ret.push_back(_set);
            }
        }
    }
};



