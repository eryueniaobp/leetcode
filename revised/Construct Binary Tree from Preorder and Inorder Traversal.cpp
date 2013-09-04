/**
 * O(n)
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       	if(inorder.size() == 0 && preorder.size() == 0 ){
			return NULL;
		}
		return buildMyTree(inorder,preorder,0,inorder.size(),0,preorder.size()) ; 
	}
	TreeNode *buildMyTree(vector<int> &inorder,vector<int> &preorder,int is,int ie,int ps,int pe){
		int rval = preorder[ps];
		TreeNode *root = new TreeNode(rval);
		for(int i = ie-1 ;i>=is ; i--){
			if(rval == inorder[i]){
				int rlen = ie-1-i;// nodes of right child-tree
				if(rlen == 0 ) {
					root->right =  NULL ;
				}
				int llen = i-is ; 
				if(llen == 0 ) {
					root->left = NULL ;
				}
				if(rlen > 0 ){
					root->right= buildMyTree(inorder,preorder,i+1,ie,pe-rlen,pe);
				}
				if(llen > 0 ) {
					root->left = buildMyTree(inorder,preorder,is,is+llen,ps+1,ps+llen+1);
				}
				return root;
			}
		}
    }
	
};

