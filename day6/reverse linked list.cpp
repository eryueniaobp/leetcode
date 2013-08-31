class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 1 ; 
        ListNode *node = new ListNode(INT_MIN);
    	node->next = head; 
		head = node;
		m++ ; n++;
        ListNode *pre = NULL, *tail = NULL,* pn = NULL;
        while(i < m ) {
            pre = node;
            node = node->next;
            i++;
        }
        
        while(i<n ) {
            node = node->next;
            i++;
        }
        tail = node->next;
        pn = pre->next;
        pre->next = node ;
        
        i = 0; 
        while( i++ < n-m ) {
            pre = pn ->next ;
            pn->next = tail;
            tail = pn ;
            pn = pre;
        }
        pn->next = tail ;

        return head->next;
    }
};

