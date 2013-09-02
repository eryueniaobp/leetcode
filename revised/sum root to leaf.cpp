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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL ) return  0 ;
        return sum(root, 0 ) ;
    }
    int sum(TreeNode *node, int pNum){
        
        int cur = pNum*10 + node->val;
        int l = 0 ,r = 0 ;
        if(node->left){
            l = sum(node->left,cur) ;
        }
        if(node->right){
            r = sum(node->right ,cur) ;
        }
        if(l == 0 && r == 0) {
            return cur ; 
        }
        return l+r; 
    }
};

