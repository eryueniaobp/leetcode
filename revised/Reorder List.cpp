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
    // TLE 
    void reorderList_(ListNode *head) {
        if(head == NULL || head->next == NULL ) return; 
        ListNode *node = head , *pre = NULL ; 
        while(node->next!=NULL){
            pre = node ; 
            node= node->next ; 
        }
        pre->next = NULL ; 
        node->next = head->next ; 
        head->next = node ; 
        
        reorderList(node->next) ; 
        
    }
    void reorderList(ListNode *head){
        if(head == NULL || head->next == NULL) return; 
        vector<ListNode* > v; 
        while(head != NULL) {
            v.push_back(head) ; 
            head = head->next ; 
        }
        int size = v.size(); 
        for(int i = 0 ; i< size/2 ; i ++ ) {
            int t = size -1 - i ; 
            v[i]->next = v[t ] ; 
            v[t]->next = v[i+1] ; 
        }
        v[size/2]->next = NULL ; 
        
    }
};

