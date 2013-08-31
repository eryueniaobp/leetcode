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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * cur = head ,*tail = NULL;
        head = NULL;
        if(cur == NULL ){
            return cur;
        }
        bool hflag =false;
        while(cur != NULL){
            ListNode * next = cur->next;
            bool flag = false;
            while(next!=NULL&&cur->val == next->val){
                next = next->next;
                flag = true;
            }
            if(flag){
                cur = next; // don't move tail
            }else{
                if(!hflag){
                    //first find head and tail
                    hflag = true;
                    head = cur;
                }else{
                    tail->next = cur;
                }
                tail = cur;
                cur = cur->next;
                tail->next = NULL;
            }
        }
        return head;
    }
};

