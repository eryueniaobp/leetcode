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
    int depthSum;
    int targetSum;
    bool depthSearch(TreeNode* root)
    {
        if(root)
        {
            if(root->right == NULL && root->left == NULL)
            {
                if(depthSum + root->val == targetSum)    return true;
                else    return false;
            }
            depthSum += root->val;
            bool res1 = depthSearch(root->left);
            bool res2 = depthSearch(root->right);
            depthSum -= root->val;
            return res1||res2;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        depthSum = 0;
        targetSum = sum;
        return depthSearch(root);
    }
};

