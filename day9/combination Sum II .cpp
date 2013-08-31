class Solution {
    vector<vector<int> > _ret;
    vector<int> _node;
public:
    void dfs(vector<int> &candidates,int target,int cur,int level){
        unordered_set<int> tag ; 
        for(int i = level ; i< candidates.size() ; i++ ) {
            if(tag.find(candidates[i]) != tag.end()){
                continue;
            }
            tag.insert(candidates[i]);
            if(cur + candidates[i] > target ){
                break;
            }else if(cur + candidates[i] < target){
                _node.push_back(candidates[i]);
                dfs(candidates , target, cur+candidates[i],i+1) ;
                _node.pop_back();
            }else{
                _node.push_back(candidates[i]);
                _ret.push_back(_node);
                _node.pop_back();
            }

        }
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(),candidates.end());
        _ret.clear();
        _node.clear();
        dfs(candidates,target,0,0); 
        return _ret;
    }
};
