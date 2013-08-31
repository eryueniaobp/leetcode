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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret ;
        if(head!=NULL && head->next != NULL ) ret = head->next;
        else{
            return head;
        }
        ListNode *node = head , *pre = NULL ;
        while(node!=NULL && node->next!=NULL){
            ListNode * p = node->next;
            node->next =  node->next->next ;  
            p->next = node;
            if(pre != NULL ) pre->next =  p ;
            pre = node;
            node = node->next;
        }
        return ret;
    }
};


