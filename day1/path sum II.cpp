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
    int targetSum;
    int depthSum;
    vector<vector<int> > res;
    vector<int> cur;
    void depthSearch(TreeNode* root)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL)
            {
                if(root->val + depthSum == targetSum)
                {
                    cur.push_back(root->val);
                    res.push_back(cur);
                    cur.pop_back();
                }
                return;
            }
            depthSum += root->val;
            cur.push_back(root->val);
            depthSearch(root->left);
            depthSearch(root->right);
            depthSum -= root->val;
            cur.pop_back();
        }
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        cur.clear();
        depthSum = 0;
        targetSum = sum;
        depthSearch(root);
        return res;
    }
};

