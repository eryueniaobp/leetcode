/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 枚举 复杂度较高
 */
class Solution {
public:
    vector<TreeNode *> build(int l,int r) {
        vector<TreeNode *> nodes;
        if(l > r) {
            nodes.push_back(NULL);
            return nodes;
        }
        for(int i = l ; i < r+1 ; i++){
           vector<TreeNode*> left  = build(l,i-1);
           vector<TreeNode*> right = build(i+1,r);
           for(int j = 0 ; j<left.size(); j++)
               for(int k = 0 ; k<right.size() ;k++){
                   TreeNode *node = new TreeNode(i);
                   node->left = left[j] ;
                   node->right = right[k];
                   nodes.push_back(node);
               }
        }
        return nodes;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(1,n);
    }
};

