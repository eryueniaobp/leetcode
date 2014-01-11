/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL ; 
         
        unordered_map<RandomListNode * , RandomListNode * > r2c ;  
        RandomListNode *node = head  , *pre = NULL ; 
        
        while(node != NULL) {
            RandomListNode *cur = NULL ; 
            if(r2c[node] == NULL) {
                cur = new RandomListNode(node->label) ; 
                r2c[node] = cur; 
                 
            }else{
                cur = r2c[node] ; 
            }
            
            if(pre != NULL)  pre->next = cur;  
            pre = cur; 
            if( node->random != NULL) {
                if(r2c[node->random] == NULL) {
                    cur->random = new RandomListNode(node->random->label) ;
                    r2c[node->random] = cur->random;
                }else{
                    cur->random = r2c[node->random] ;
                }
            }else{
                cur->random = NULL ; 
            }
            
            node = node->next; 
            
        }
            
        
        return r2c[head]; 
    }
};

