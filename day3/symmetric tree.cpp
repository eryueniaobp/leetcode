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
    bool check(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (leftNode == NULL && rightNode == NULL)
            return true;
            
        if (leftNode == NULL || rightNode == NULL)
            return false;
            
        return leftNode->val == rightNode->val && check(leftNode->left, rightNode->right) && 
            check(leftNode->right, rightNode->left);
    }
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return true;
            
        return check(root->left, root->right);
    }
};

