/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
  * complexity:  O(K)  +  (n-k)lgK  ;  
  */
  bool cmp (const ListNode *a  , const ListNode *b)   {
        if( a == NULL ) return true; 
        if( b == NULL)  return false; 
        return a->val > b->val ;
    }
class Solution {
public:
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size(); 
        if(k == 0 ) return NULL ; 
        if( k==1 )  return lists[0]; 
        ListNode *head = NULL , * cur = NULL ; 
        make_heap(lists.begin() , lists.end() ,cmp ) ; 
        head = lists[0] ;
        if(head == NULL) return NULL ; 
        int size = k  ; 
        while(k > 0 ) {
            if(cur == NULL)  {
                cur = lists[0] ; 
            }else{
                cur->next = lists[0] ; 
                cur= cur->next; 
            }
            if(lists[0] == NULL) break ; 
            pop_heap(lists.begin(),lists.begin() + k ,cmp) ;  
            lists[k-1] = lists[k-1]->next ; 
            if(lists[k-1] == NULL) {
                
                k-- ; 
            }else{
                push_heap(lists.begin(),lists.begin()+k,cmp) ; 
            }
        }
        return head ; 
    }
};

