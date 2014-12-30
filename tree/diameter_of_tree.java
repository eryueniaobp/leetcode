// Amazon Sample Test.
/**
* In particular, note that the diameter of a tree T is the largest of the following quantities:
* the diameter of T's left subtree
* the diameter of T's right subtree
* the longest path between leaves that goes through the root of T
* Given the root node of the tree, return the diameter of the tree
*/
static int diameterOfTree(Node root) {
    if(root == null) return 0 ; 
    return Math.max( Math.max(diameterOfTree(root.left) ,diameterOfTree(root.right)) , 
                    depth(root.left) + depth(root.right) + 1  ) ; 
}
static int depth(Node root) {
    if(root == null) return  0 ; 
    return Math.max( depth(root.left) , depth(root.right) ) + 1 ; 
}
