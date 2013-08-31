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
    vector<TreeNode *> generate(int beg, int end)
    {
        vector<TreeNode* > ret;
        if (beg > end)
        {
            ret.push_back(NULL);
            return ret;
        }
        
        for(int i = beg; i <= end; i++)
        {
            vector<TreeNode* > leftTree = generate(beg, i - 1);
            vector<TreeNode* > rightTree = generate(i + 1, end);
            for(int j = 0; j < leftTree.size(); j++)
                for(int k = 0; k < rightTree.size(); k++)
                {
                    TreeNode *node = new TreeNode(i + 1);
                    ret.push_back(node);
                    node->left = leftTree[j];
                    node->right = rightTree[k];              
                }           
        }
        
        return ret;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generate(0, n - 1);
    }
};

