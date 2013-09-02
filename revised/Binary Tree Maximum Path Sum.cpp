/**
 * O(n) 
 */
class Solution {
public:
    int maxSum;
    int maxPathSum(TreeNode *root) { 
        // Start typing your C/C++ solution below 
        // DO NOT write int main() function
        maxSum = INT_MIN;
        getMax(root);
        return maxSum;
    }
    int getMax(TreeNode *root)
    {
        if(root == NULL ) return  0 ;
        int temp1 = getMax(root->left);
        if(temp1 < 0){
            temp1 = 0;
        }
        int temp2 = getMax(root->right);
        if(temp2 < 0){
            temp2 = 0;
        }

        int sum =root->val +  temp1 + temp2;
        if(sum > maxSum)
            maxSum = sum;

        return  root->val + max(temp1,temp2);
    }
};

