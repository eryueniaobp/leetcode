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
		return md(root);        
    }
	int md(TreeNode *root){
		if(root == NULL) return 0;
		int l =  md(root->left);
		int r =  md(root->right);
		if( l == 0 || r == 0 ) {
			return 1+l+r; 
		}
		return l<r?(l+1):(r+1);
	}
};

