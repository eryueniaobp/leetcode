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
		ans.push_back(vector<int>(1,root->val));	
        int count = 1; 
		TreeNode * nd = NULL; 
		while(true){
            int ncount = 0 ;
            vector<int> lvec;
			while(count-->0){
				nd = nodes.front();
				nodes.pop_front();
				if(nd->left != NULL){
					nodes.push_back(nd->left);
                    lvec.push_back(nd->left->val);
                    ncount++;
				}
				if(nd->right!=NULL){
					nodes.push_back(nd->right);
                    lvec.push_back(nd->right->val);
                    ncount++;
				}
			}
            count = ncount ; 
            if(count == 0 ) break;
            ans.push_back(lvec);
        }
        for(int i = 0 ; i<ans.size()/2 ; i++){
			swap(ans[i],ans[ans.size()-1-i]);
		}
        return ans;
    }
};


