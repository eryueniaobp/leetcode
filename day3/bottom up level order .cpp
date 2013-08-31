/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
      vector<vector<int> > levelOrderBottom(TreeNode *root) {    
		// Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int>> ans;
		if(!root) {
			return ans;
		}
		deque<TreeNode*> nodes ;
		nodes.push_back(root);
		deque<TreeNode*> level;
		ans.push_back(vector<int>(1,root->val));	
		int s , e ; 
		s = e = -1;
		TreeNode * nd = NULL; 
		while(true){
			while(nodes.size()>0){
				nd = nodes.front();
				nodes.pop_front();
				if(nd->left != NULL){
					level.push_back(nd->left);
				}
				if(nd->right!=NULL){
					level.push_back(nd->right);
				}
			}
			vector<int> lvec ; 
			while(level.size()>0){
				nd = level.front();
				level.pop_front();
				lvec.push_back(nd->val);
				nodes.push_back(nd);
			}
			if(lvec.size() == 0 ) break;
			ans.push_back(lvec);
		}
		for(int i = 0 ; i<ans.size()/2 ; i++){
			swap(ans[i],ans[ans.size()-1-i]);
		}
	 	return ans;				
    }
};


