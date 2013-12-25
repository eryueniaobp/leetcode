/**
 * Given a binary tree where all the right nodes are either empty or leaf nodes, flip it upside down
 * and turn it into a tree with left leaf nodes.
 * In the original tree, if a node has a right child, it also must have a left child.
 *
 * for example, turn these:
 *
 *        1                1
 *       / \              / \
 *      2   3            2   3
 *     /
 *    4
 *   / \
 *  5   6
 *
 * into these:
 *
 *        1               1
 *       /               /
 *      2---3           2---3
 *     /
 *    4
 *   /
 *  5---6
 *
 * where 5 is the new root node for the left tree, and 2 for the right tree.
 * oriented correctly:
 *
 *     5                  2
 *    / \                / \
 *   6   4              3   1
 *        \
 *         2
 *        / \
 *       3   1
 *
 */
class TreeNode {
    TreeNode left;
    TreeNode right;
    int data;
}
 
public TreeNode reverse(TreeNode node) {
    // implementation here    
    if(node == null ) return null; 
    Stack stack = new Stack(); 
    TreeNode root = null , temp =  node;  
    while(temp!=null) {
        stack.push(temp);
        root = temp ; 
        temp = temp.left;             
    }
    TreeNode troot = root;  
    stack.pop() ;
    TreeNode left ,right ; 
    while(!stack.isEmpty()){ 
        temp = stack.pop() ; 
        left = temp.left ;
        right =temp.right;  

        troot.right = temp ;
        troot.left = right ;

        troot = temp ; 
    }
    return root; 
} 
