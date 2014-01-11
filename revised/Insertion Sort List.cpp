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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL) return NULL ; 
        ListNode *tail = head , * cur = tail->next ;
        ListNode *tmp  = NULL , *pre = NULL ; 
        while(cur!=NULL){
            tmp = head; pre = NULL ;
            while(tmp!=cur && cur->val >= tmp->val) {
                pre = tmp ; 
                tmp = tmp->next; 
            }
            
            if(tmp == cur) {
                tail = cur ; 
            }else{
                if(pre != NULL ) {
                    pre->next = cur ; 
                    tail->next = cur->next ; 
                    cur->next = tmp ;
                }else{
                    tail->next = cur->next ; 
                    cur->next = head ; 
                    head = cur ;
                }
            }
            
            cur = tail->next; 
        }
        return head; 
    }
};

