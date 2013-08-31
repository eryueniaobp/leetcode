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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!root) return true;
		bool flag = true;
		height(root,flag);
		return flag;
    }
	
	int height(TreeNode * root,bool &flag){
		if(root == NULL) return 0 ;
		int lh = height(root->left,flag);
		int rh = height(root->right,flag);
		int h  = 1+max(lh,rh);
		if(lh - rh > 1 || rh -lh > 1){
			flag = false;
		}
		return h;	
	}
};

