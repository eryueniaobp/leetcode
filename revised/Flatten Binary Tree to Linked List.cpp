/**
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

*/
/**
 * Time: O(n) 
 * Space: O(1)
 * Step 1 . 左变右 
 * Step 2 . 取原左子树的最右节点，接到原右节点上    
 * 重复上面两个步骤即可
 * Do it in-place . So pre-order visit simply doesn't work here.
 * Hint:It's another way to do the pre-order traverse even without STACK! but maybe its complexity is not O(N) 
 */
class Solution {
public:
    void flatten(TreeNode *root) {
       
        while(root!=NULL){
            if(root->left != NULL ){
                TreeNode *left = root->left ; 
                TreeNode *right = root->right ; 
                root->left = NULL ; 
                root->right = left ;
                TreeNode *rightMost = left; 
                while(rightMost ->right != NULL ) { 
                    rightMost = rightMost->right; 
                }   
                rightMost->right = right ; 
            }
            root = root->right ; 
        }
    }   
};
