/**
 * DFS 即可
 */
class Solution {
    vector<vector<int> > ret_;
    vector<int> node_;
public:
    void dfs(vector<int> &candidates,int target,int cur,int level){
        for(int i = level ; i< candidates.size() ; i++ ) {
            if(cur + candidates[i] > target ){
                break;
            }else if(cur + candidates[i] < target){
                node_.push_back(candidates[i]);
                dfs(candidates , target, cur+candidates[i],i) ;
                node_.pop_back();
            }else{
                node_.push_back(candidates[i]);
                ret_.push_back(node_);
                node_.pop_back();
            }

        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(),candidates.end());
        ret_.clear();
        node_.clear();
        dfs(candidates,target,0,0); 
        return ret_;
    }
};


