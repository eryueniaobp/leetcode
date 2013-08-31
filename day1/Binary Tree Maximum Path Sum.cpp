class Solution {
public:
    int max;
    int maxPathSum(TreeNode *root) { 
        // Start typing your C/C++ solution below 
        // DO NOT write int main() function
        max = -9999999;
        getMax(root);
        return max;
    }
    int getMax(TreeNode *root)
    {
        int c1 = root->val;
        int c2 = c1;
        int temp1 = 0;
        int temp2 = 0;
        if(root->left != NULL)
        {
            temp1 = getMax(root->left);
            if(temp1 < 0)
                temp1 = 0;
        }
        if(root->right != NULL)
        {
            temp2 = getMax(root->right);
            if(temp2 < 0)
                temp2 = 0;
        }
        c1 += (temp1 >= temp2)?temp1:temp2;
        c2 += temp1 + temp2;
        if(c2 > max)
            max = c2;
        return c1;
    }
};

