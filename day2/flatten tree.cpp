class Solution {
      deque<TreeNode*> pdq;
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL){
            return;
        }
        pdq.clear();
        preorder(root);   
        root = pdq.front(); pdq.pop_front();
        TreeNode * node = root ;
        while(!pdq.empty()){            
            node->left = NULL ; 
            node->right = pdq.front();
            node = node->right;
            pdq.pop_front();
        }    
    }
    void preorder(TreeNode *root){
        if(root == NULL) return;
        pdq.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
};

