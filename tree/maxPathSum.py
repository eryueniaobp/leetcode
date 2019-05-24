# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        if root == None: return 0 
        self.ret = -2**31  
        def maxPath(node):
            if node == None: return 0 
            left = maxPath(node.left)
            right = maxPath(node.right)
            
            if max(left, 0) + node.val + max(right, 0) > self.ret :
                self.ret = max(left, 0)  + node.val + max(right, 0) 
            return node.val +  max(max(left, right), 0)
        maxPath(root)
        
        return self.ret 
