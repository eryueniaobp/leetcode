/**
 * dfs + 标记数组避免重复
 */
class Solution {
    vector<vector<int> > ret_;
    vector<int> node_;
public:
    void dfs(vector<int> &candidates,int target,int cur,int level){
        unordered_set<int> tag ; 
        for(int i = level ; i< candidates.size() ; i++ ) {
            if(tag.count(candidates[i]) >0){
                continue;
            }
            tag.insert(candidates[i]);
            if(cur + candidates[i] > target ){
                break;
            }else if(cur + candidates[i] < target){
                node_.push_back(candidates[i]);
                dfs(candidates , target, cur+candidates[i],i+1) ;
                node_.pop_back();
            }else{
                node_.push_back(candidates[i]);
                ret_.push_back(node_);
                node_.pop_back();
            }

        }
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(),candidates.end());
        ret_.clear();
        node_.clear();
        dfs(candidates,target,0,0); 
        return ret_;
    }
};

