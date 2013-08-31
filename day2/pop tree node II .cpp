/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(NULL == root){
            return;
        }

        TreeLinkNode *cur = root->next;
        TreeLinkNode *p = NULL;
        
        while(cur != NULL && cur->left ==NULL && cur->right==NULL){     // find last right node (left or right)
            cur = cur->next;
        }
        if(cur!=NULL){
            if(cur->left != NULL ) {
                p = cur->left;
            }else{
                p = cur->right;
            }
        }

        if(root->right){
            root->right->next = p;
        }
        
        if(root->left){
            root->left->next = root->right ? root->right : p;
        }
        
        connect(root->right);   // from right to left
        connect(root->left);
    }
};

