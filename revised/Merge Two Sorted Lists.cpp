/** 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * head = NULL ;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        head =( l1->val<l2->val?l1:l2);
        ListNode * node = head;
        while(true){
            while(l1!=NULL && l1->val < l2->val){
                node = l1;
                l1 = l1->next;
            }
            if(node != l2 ){
                node->next = l2;
            }
            if(l1 == NULL) break;
            while(l2!=NULL && l2->val <= l1->val){
                node = l2;
                l2 = l2->next;
            }
            node->next = l1;
            if(l2 == NULL ) break;
        }
        
        
        return head;
    }
};

