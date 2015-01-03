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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int>> ans;
		if(!root) {
			return ans;
		}
		deque<TreeNode*> nodes ;
		nodes.push_back(root);
		ans.push_back(vector<int>(1,root->val));	
        int count = 1; 
		TreeNode * nd = NULL; 
		while(true){
            int ncount = 0 ;
            vector<int> lvec;
			while(count-->0){
				nd = nodes.front();
				nodes.pop_front();
				if(nd->left != NULL){
					nodes.push_back(nd->left);
                    lvec.push_back(nd->left->val);
                    ncount++;
				}
				if(nd->right!=NULL){
					nodes.push_back(nd->right);
                    lvec.push_back(nd->right->val);
                    ncount++;
				}
			}
            count = ncount ; 
            if(count == 0 ) break;
            ans.push_back(lvec);
        }
        return ans;		
    }
};

/** better solutin of java **/
public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>() ; 
        if(root == null) return ret; 
        int pcnt = 1 , cnt = 0 ; 
        Queue<TreeNode> queue  = new LinkedList<TreeNode>() ;
        queue.offer(root) ; 
        ArrayList<Integer> row = new ArrayList<Integer>() ; 
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
                ret.add(row) ; 
                row = new ArrayList<Integer>() ; 
                pcnt = cnt ; 
                cnt = 0 ; 
            }
        }
        return ret; 
    }
}


