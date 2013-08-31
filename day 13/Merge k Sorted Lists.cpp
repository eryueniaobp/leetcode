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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * head = NULL , *cur=NULL,*pre = NULL; 
        while(true){

            int min = INT_MAX;
            int mp = -1;
            int i = 0 ; 
            for( ;i < lists.size(); i ++  ){
                if(lists[i] == NULL ) continue;
                if(lists[i]->val < min ) {
                    min = lists[i]->val;
                    mp = i ;
                }
            }
            if(mp>=0){
                lists[mp] = lists[mp]->next;
                if(head == NULL){
                    head = new ListNode(min);
                    pre = head;
                }else{
                    cur = new ListNode(min);
                    pre->next = cur;
                    pre = cur;
                }
            }else{
                return head;
            }
        }
    }
};


