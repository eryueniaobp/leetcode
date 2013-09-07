/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * O(n) 
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * cur = head;
        if(cur == NULL ){
            return cur;
        }
        while(cur != NULL){
            ListNode * next = cur->next;
            while(next!=NULL&&cur->val == next->val){
                next = next->next;
            }
            cur->next = next;
            cur = next;
        }
        return head;
    }
};

