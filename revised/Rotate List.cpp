/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 先首尾相连，然后再rotate
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return NULL;
        if( k == 0 ) return head;
        int i = 1 ;
        ListNode* cur = head;
        while(cur->next!=NULL){
            i++ ; 
            cur= cur->next;
        }
        k = k%i;
        cur->next = head; 
        cur = head ; 
        i = i - k ;
        while(cur!=NULL && i > 1 ){
            cur = cur->next;
            i--;
        }
        head = cur->next ; 
        cur->next = NULL ;
        return head;
    }
};


