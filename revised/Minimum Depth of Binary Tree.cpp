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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return 0;
		int l =  minDepth(root->left);
		int r =  minDepth(root->right);
		if( l == 0 || r == 0 ) {
			return 1+l+r; 
		}
		return min(l+1,r+1);
	}
};

