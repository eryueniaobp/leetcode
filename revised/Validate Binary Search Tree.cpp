/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * O(n) 遍历一遍
 */
class Solution {
public:
    bool check(TreeNode *node, int leftVal, int rightVal)
    {
        if (node == NULL)
            return true;
            
        return leftVal < node->val && node->val < rightVal && check(node->left, leftVal, node->val) &&
            check(node->right, node->val, rightVal);
    }
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return check(root, INT_MIN, INT_MAX);        
    }
};


