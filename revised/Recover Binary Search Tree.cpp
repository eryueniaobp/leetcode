/**
 * O(n) 遍历一遍 
*Two elements of a binary search tree (BST) are swapped by mistake.
*
*Recover the tree without changing its structure.
*
*Note:
*A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 * 
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
// -------------------------------------------------------------------
// traverse iteratively 

/**
 * Definition for binary tree
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void recoverTree(TreeNode root) {


        TreeNode p = root;
        Stack<TreeNode> st = new Stack<TreeNode>();
        TreeNode pre = new TreeNode(Integer.MIN_VALUE) ;
        TreeNode first = null;
        TreeNode second = null;
        while(!st.isEmpty() || p!=null) {
            while(p!=null){
                st.push(p) ;
                p = p.left ;

            }
            if(!st.isEmpty()){
                p = st.pop() ;
                if( pre.val > p.val) {
                    if(first == null) {
                        first = pre;
                        second = p ;
                    }else{
                        second = p ; 
                        break; 
                    }
                }
                pre =   p ;
                p = p.right ;
            }
        }
        int tmp = first.val ;
        first.val = second.val ;
        second.val = tmp ; 
    }
}
