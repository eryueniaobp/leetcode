/**
 * dfs 每一层加入标记位，检测是否重复
 */
class Solution {
    vector<vector<int> > ret_;
    vector<int> perm_;
    unordered_set<int> set_;
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret_.clear();
        set_.clear();
        perm_.clear();
        dfs(num,0);  
        return ret_;
    }
    void dfs(vector<int> &num ,int l){
        if( l == num.size() ) {
            ret_.push_back(perm_);
            return;
        }
        unordered_set<int> lset;
        for(int i = 0 ;i<num.size(); i ++){
            if(set_.find(i) != set_.end()) {
                continue;
            }
            if( lset.find(num[i]) != lset.end() ){
                continue;
            }
            lset.insert(num[i]); 
            perm_.push_back(num[i]);
            set_.insert(i);
            dfs(num,l+1);
            set_.erase(i);
            perm_.pop_back();
        }
        lset.clear();
    }
};



