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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head ->next == NULL ) return false ; 
        ListNode *fast = head->next , *slow = head ; 
        while(fast != NULL && slow != NULL ){
            if(fast == slow ) return true; 
            fast = fast->next  ;
            if(fast != NULL ) fast = fast->next; 
            else{
                return false; 
            }
            slow = slow->next; 
        }
        return false; 
    }
};

