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
    TreeNode *flattenWithNode(TreeNode *root){
        if(root == NULL ) return NULL ; 
        TreeNode * lend = flattenWithNode(root->left) ;  
        if(lend == NULL ) {
            lend = root ;
        }
        TreeNode * right = root->right;  
        root->right = root->left ; 
        root->left = NULL ;

        lend->right = right ; 

        if(right == NULL ) return lend ;
        return flattenWithNode(right) ;
        
         
    }
    void flatten(TreeNode *root) {
        flattenWithNode(root); 
    }
};


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
    TreeNode *flattenWithNode(TreeNode *root){
        if(root == NULL ) return NULL ; 
        TreeNode * lend = flattenWithNode(root->left) ;  
        if(lend == NULL ) {
            lend = root ;
        }
        TreeNode * right = root->right;  
        root->right = root->left ; 
        root->left = NULL ;

        lend->right = right ; 

        if(right == NULL ) return lend ;
        return flattenWithNode(right) ;
        
         
    }
    void flatten(TreeNode *root) {
        flattenWithNode(root); 
    }
};

