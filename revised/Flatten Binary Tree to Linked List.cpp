/**
 * Time: O(n) 
 * Space: O(1)
 * Step 1 . 左变右 
 * Step 2 . 取原左子树的最右节点，接到原右节点上    
 * 重复上面两个步骤即可
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

