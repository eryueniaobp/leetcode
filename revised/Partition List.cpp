/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * O(n) 每次都会将一个元素放到合适的位置
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * big = NULL;
        ListNode * small = NULL ;
        ListNode *bigHead = NULL;
        if(head == NULL ) {
            return head;
        }
        if(head->val>=x){
            bigHead = head;
        }
        while(head!=NULL &&head->val >=x ) {
            big = head;
            head = head->next;
        }
        small = head; 
        if(small == NULL ) {
            return bigHead;
        }

        //has finded real head 
        while(true){
            ListNode *tmp = NULL;
            while(small!=NULL&&small->val <x ){
                tmp = small;
                small = small ->next;
            }
            if(big == NULL ){
                big = small ;
                bigHead = big;
            }else{
                big->next =small ;
                big = big->next;
            }
            small = tmp;
            while(big != NULL && big->val >= x) {
                tmp = big;
                big=  big->next;
            }
            
            if(big == NULL ){
                break;
            }else{
                small->next = big;
                small = big;
            }
            big =tmp;
        }

        small->next = bigHead;
        return head;
    }
};


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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL) return NULL; 
        ListNode *rhead = NULL , *rtail = NULL ; 
        ListNode *ltail = NULL , *lhead = NULL ; 
        while(head!=NULL && head->val < x ) {
            if(lhead == NULL )  lhead = head ; 
            ltail = head ;
            head = head->next; 
        }
        
        while(head!= NULL) {
            while(head!=NULL && head->val >= x) {
                if(rhead == NULL) rhead = head; 
                rtail = head; 
                head = head->next; 
            }
            if(head == NULL) {
                return lhead!=NULL ? lhead : rhead; 
            }else{
                if(ltail==NULL) {
                    lhead = head ; 
                    ltail = head; 
                    rtail->next = head->next; 
                    
                    ltail->next = rhead; 
                    
                }else{
                    ltail->next = head ; 
                    ltail = head; 
                    
                    rtail->next = head->next; 
                    ltail->next = rhead ; 
                }
                head = rtail->next; 
            }
        }
        
        return lhead; 
    }
};


