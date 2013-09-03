/**
 * Time: O(n) 
 * Space: O(1)
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL ) return; 
        if(root->left != NULL ){
            TreeNode *left = root->left ; 
            TreeNode *right = root->right ; 
            root->left = NULL ; 
            root->right = left ;
            TreeNode *rightMost = root->right; 
            while(rightMost ->right != NULL ) {
                rightMost = rightMost->right; 
            }
            rightMost->right = right ; 
        }
        flatten(root->right) ;
    }
};

