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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret; 
        if(root == NULL) return ret; 
        unordered_map<TreeNode* , int > n2c ; 
        stack<TreeNode* > s ; 
        s.push(root) ;
        TreeNode *node = NULL ;
        while(!s.empty()){
            node = s.top() ;
            if(n2c[node] == 0 ) {
                n2c[node] =1 ;
                if(node->left!=NULL)  s.push(node->left) ;  
            }else if(n2c[node] == 1 ) {
                n2c[node] = 2; 
                if(node->right != NULL ) s.push(node->right);
            }else{
                s.pop(); 
                ret.push_back(node->val) ;
            }
        }
        return ret;

    }
};

