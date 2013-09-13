/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 扫描一遍 双指针
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *cur = head, *left = head; 
        while(--n>0){
            cur = cur->next;
        }
        
        cur = cur->next;
        if(cur == NULL ) {
            head = head->next;
            return head;
        }
        cur = cur->next;
        while(cur!=NULL){
            left = left->next;
            cur = cur->next;
        }
        left->next = left->next->next;
        return head;
        
    }
};

