/**
 * O(n) 遍历一遍 
 */
class Solution {
public:
    void treeWalk(TreeNode* root, TreeNode*& prv, TreeNode*& first, TreeNode*& second)
    {
      if(root==NULL)
         return;
      treeWalk(root->left,prv,first,second);
      if((prv!=NULL)&&(prv->val>root->val)){
          if(first==NULL)
             first=prv;
           second=root;
      }
      prv=root;
      treeWalk(root->right,prv,first,second);
    }
 
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* prv=NULL;
        treeWalk(root,prv,first,second);
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
    }
};

