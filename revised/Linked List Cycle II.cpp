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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head ->next == NULL ) return NULL ; 
        ListNode *fast = head->next->next, *slow = head->next ; 
        ListNode *meet = NULL ; 
        while(fast != NULL && slow != NULL ){
            if(fast == slow ) {
                meet = fast ; 
                break;  
            }
            fast = fast->next  ;
            if(fast != NULL ) fast = fast->next; 
            else{
                return NULL; 
            }
            slow = slow->next; 
        }
        
        if(meet == NULL )  return NULL ; 
        
        while(head != meet ) {
            head = head->next; 
            meet = meet ->next; 
        }
        return head;  
    }
};

