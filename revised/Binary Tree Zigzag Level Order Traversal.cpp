/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
// A clear java solution 
public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
    public void reverse(ArrayList<Integer> row){
        int i = 0  , j = row.size() - 1 ; 
        while( i < j ) {
            Collections.swap(row, i++ , j-- ) ; 
        }
    }
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        // write your code here
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>() ; 
        if(root == null) return ret; 
        int pcnt = 1 , cnt = 0 ; 
        Queue<TreeNode> queue  = new LinkedList<TreeNode>() ;
        queue.offer(root) ; 
        ArrayList<Integer> row = new ArrayList<Integer>() ; 
        boolean zig = true;  
        while(pcnt > 0  ) {
            TreeNode n = queue.poll() ; 
            row.add(n.val) ; 
            if(n.left != null)  { 
                queue.offer(n.left ) ; cnt++ ; 
            }
            if(n.right!=null){
                queue.offer(n.right) ; cnt++ ;
            }
            pcnt--; 
            if(pcnt == 0  ) {
                if(zig) {
                    ret.add(row) ; 
                }else{
                    reverse(row)  ; 
                    ret.add(row); 
                }
                row = new ArrayList<Integer>() ; 
                pcnt = cnt ; 
                cnt = 0 ; 
                zig = !zig ;
            }
        }
        return ret; 

    }
}
// ---------------------------------------------------------
// C++ solution
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int>> ans;
		if(!root) {
			return ans;
		}
		deque<TreeNode*> nodes ;
		nodes.push_back(root);
        int count = 1;
		ans.push_back(vector<int>(1,root->val));	
		TreeNode * nd = NULL; 
		bool right = true;
		while(true){
            int ncount = 0 ;
            vector<int> lvec;
			while(count-->0){
				nd = nodes.front();
				nodes.pop_front();
				if(nd->left != NULL){
					nodes.push_back(nd->left);
                    lvec.push_back(nd->left->val);
                    ncount ++ ;
				}
				if(nd->right!=NULL){
					nodes.push_back(nd->right);
                    lvec.push_back(nd->right->val);
                    ncount ++ ;
				}
			}
            count = ncount ;
            if(count == 0 ) break; 
			if(right){
				//reverse
				for(int i = 0 ; i<lvec.size()/2;i++){
					swap(lvec[i],lvec[lvec.size()-1-i]);
				}	
			}
			ans.push_back(lvec);
			right = !right;
		}
	 	return ans;				
    }
};


