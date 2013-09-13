/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * O( m + n ) 遍历一遍
 */
class Solution {
public:
    
    ListNode *singleLink(ListNode*& l1,ListNode *&cur,int &c){
        while(l1 != NULL){
            int sum = l1->val + c;
            cur->val = sum%10;
            c = sum/10;
            l1= l1->next;
            if( l1 == NULL && c == 0 ){
                cur->next = NULL;
            }else{
                cur->next = new ListNode(0);
                cur = cur->next;
            }
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * head = new ListNode(0); 
        ListNode * cur = head;
        int c = 0 ;
        while(l1!=NULL && l2!=NULL){
            int sum =  (l1->val + l2->val + c );
            cur->val = sum%10;
            c = sum/10;
            l1 = l1->next;
            l2= l2->next;
            if(l1 == NULL && l2==NULL && c == 0 ){
                cur->next= NULL;
            }else{
                cur->next = new ListNode(0);
                cur = cur->next;
            }
        }
        singleLink(l1,cur,c);
        singleLink(l2,cur,c);
        if(c > 0 ){
            cur->val = c; 
            cur->next = NULL ;
        }
        return head;
    }
};

