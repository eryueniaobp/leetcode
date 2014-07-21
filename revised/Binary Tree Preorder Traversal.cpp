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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int>  ret ; 
        if(root == NULL ) return ret; 
        stack<TreeNode* > s ; 
        TreeNode * p = root; 
        while( p!= NULL || !s.empty() ) {
            while(p != NULL ) {
                ret.push_back(p->val) ; // visit 
                s.push(p) ; 
                p = p->left; 
            }
            if(!s.empty()) { 
                p = s.top() ; 
                s.pop();  //放右节点时，把当前根弹出.栈中的顺序是ok的
                p = p->right; 
            }
        }
    }
};


