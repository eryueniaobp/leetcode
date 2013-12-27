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
        bool isRight(TreeNode * node1 , TreeNode * node2)
        {
            if(node1 == NULL && node2 == NULL ) return true; 
            if(node1 == NULL ) return false; 
            if(node2 == NULL ) return false; 

            if(node1->val != node2->val ) return false; 

            return isRight(node1->left,node2->right) && isRight(node1->right,node2->left ) ;
        }
        bool isSymmetric(TreeNode *root) 
        {
            if(root == NULL ) return true; 
            return isRight(root->left,root->right); 
        }
};

