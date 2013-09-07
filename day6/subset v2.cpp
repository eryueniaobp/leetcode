class Solution {
    int size_;
    vector<vector<int> > ret_;
    vector<int> set_;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_ = S.size();
        sort(S.begin(),S.end(),less<int>());
        ret_.clear();
        set_.clear();
        dfs(S,0);  
        return ret_;
    }
    void dfs(vector<int> &S, int l){
        if(l == size_ ){
            ret_.push_back(set_);
            return;
        }
        for(int i =  l ; i<=size_ ;i++){
            if(i<size_){
                set_.push_back(S[i]);
                dfs(S,i+1);
                set_.pop_back();
            }else{
                ret_.push_back(set_);
            }
        }
    }
};

