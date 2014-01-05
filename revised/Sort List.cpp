/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// use quick sort ,will TLE 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode * node =head; 
        map<int,int> v2c ; 
        
        while(node!=NULL){
            v2c[node->val]++ ; 
            node= node->next; 
        }
        
        node= head; 
        map<int,int>::iterator iter = v2c.begin(); 
        while(iter != v2c.end()) {
            int c = iter->second ; 
            while(c-- ) {
                node->val = iter->first  ;
                node = node->next; 
            }
            iter ++ ; 
        }
        return head; 
    }
};
