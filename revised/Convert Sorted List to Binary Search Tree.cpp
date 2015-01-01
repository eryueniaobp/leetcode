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
/**
 * O(n) 
 * 先转成数组，然后再转化bst,时间复杂度就降低了
 * It's not proper solution. especially in an interview .
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
/*just recurse on the list. proper solution*/
/** 
 T(n) = O(n) + 2T(n/2) ,like quick-sort .
 So time complexity will be O(nlogn) 
*/
class Solution{
public:
    TreeNode* sortedListToBST(ListNode *head){
        int len = 0 ; 
        ListNode * n = head ; 
        while(n!=NULL){
            len++ ; 
            n = n->next;
        }
        return buildTree(head, 0 , len -1 ) ; 
    }
    TreeNode *buildTree(ListNode *node , int start ,int end){
        if(start > end ) return NULL ; 
        int mid = start + (end-start)/2 ;  
        ListNode *p = node ;
        int i = start ; 
        while(i < mid) {
            i++ ; p = p->next ; 
        }
        TreeNode *left = buildTree(node , start ,mid-1) ; 
        TreeNode *root = new TreeNode(p->val) ; 
        root->left = left ; 
        root->right = buildTree(p->next, mid+1,end) ; 
        return root ; 
    }
};
