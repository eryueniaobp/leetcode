/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 * DFS 
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return;
        
        if(root->left && root->right){
            root->left->next = root->right;
            root->right->next = (root->next?root->next->left:NULL);
            connect(root->left);
            connect(root->right);
        }
        
    }
};


