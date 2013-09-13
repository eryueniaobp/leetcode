/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 *
 * };
 * O(n) 链表的题目都比较琐碎.. 
 */
struct Node
{
    ListNode *beg;
    ListNode *end;
    Node(){}
    Node(ListNode *b, ListNode *e):beg(b), end(e){}
};

class Solution {
public:
    Node reverse(ListNode *beg, ListNode *end)
    {
        ListNode *pPre = NULL;
        ListNode *p = beg;
        
        while(p != end)
        {
            ListNode *pNext = p->next;
            p->next = pPre;
            pPre = p;
            p = pNext;
        }
        
        p->next = pPre;
        
        return Node(end, beg);
    }
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
        
        ListNode *pPre = NULL;  
        ListNode *p = head;
        while(p)
        {
            ListNode *q = p;
            for(int i = 0; i < k - 1; i++)
            {
                q = q->next;
                if (q == NULL)
                    return head;
            }
            
            ListNode *qNext = q->next;
            
            Node ret = reverse(p, q);
            if (pPre)
                pPre->next = ret.beg;
            else
                head = ret.beg;
            ret.end->next = qNext;
            pPre = ret.end;
            p = qNext;
        }
        
        return head;
    }
};

