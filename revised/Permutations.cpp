/**
 * dfs 
 */
class Solution {
    vector<vector<int> > ret_;
    vector<int> perm_;
    unordered_set<int> set_;
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret_.clear();
        dfs(num,0);  
        return ret_;
    }
    void dfs(vector<int> &num ,int l){
        if( l == num.size() ) {
            ret_.push_back(perm_);
            return;
        }
        for(int i = 0 ;i<num.size(); i ++){
            if(set_.find(num[i]) != set_.end()) {
                continue;
            }
            perm_.push_back(num[i]);
            set_.insert(num[i]);
            dfs(num,l+1);
            set_.erase(num[i]);
            perm_.pop_back();
        }
    }
};

