/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> num ; 
        while(head != NULL){
            num.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(num);
    }
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
