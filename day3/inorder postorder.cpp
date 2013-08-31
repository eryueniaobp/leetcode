class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       	if(inorder.size() == 0 && postorder.size() == 0 ){
			return NULL;
		}
		return buildMyTree(inorder,postorder,0,inorder.size(),0,postorder.size()) ; 
	}
	TreeNode *buildMyTree(vector<int> &inorder,vector<int> &postorder,int is,int ie,int ps,int pe){
		int rval = postorder[pe-1];
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
					root->right= buildMyTree(inorder,postorder,i+1,ie,pe-1-rlen,pe-1);
				}
				if(llen > 0 ) {
					root->left = buildMyTree(inorder,postorder,is,is+llen,ps,ps+llen);
				}
				return root;
			}
		}
    }
	
};

