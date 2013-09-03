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
    vector<vector<int> > res;
    vector<int> cur;
    void dfs(TreeNode* root,int sum) {
        if(root == NULL ) {
            return ;
        }
        cur.push_back(root->val);
        if(root->val == sum  && root->left == NULL && root->right == NULL ) {
            res.push_back(cur);
            cur.pop_back();
            return ;    
        }
        dfs(root->left , sum - root->val) ;
        dfs(root->right ,sum - root->val) ;
        cur.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        cur.clear();
        dfs(root,sum);
        return res;
    }
};


