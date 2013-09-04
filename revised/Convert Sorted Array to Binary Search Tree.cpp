/**
 * O(n)
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return makeTree(num,0,num.size());
    }
    TreeNode *makeTree(vector<int> &num,int s,int e){
        if(s>=e) {
            return NULL;                      
        }
        int pos = (s+e)/2;
        TreeNode *node = new TreeNode(num[pos]);
        node->left = makeTree(num,s,pos);
        node->right = makeTree(num,pos+1,e);
        return node;
    }
};

