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
        map<int,int> v2c ;  // tricky solution ..use RedBlack-tree map to get sorted sequence.. 
        
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
// A expected solution . 
// If use quickSort , you need to keep the whole list connected . it 's trivial. 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head||!head->next)
            return head;
        return mergeSort(head);
    }
    ListNode * mergeSort(ListNode *head){
        if(!head||!head->next)   //just one element
            return head;
        ListNode *p=head, *q=head, *pre=NULL;
        while(q&&q->next!=NULL){
            q=q->next->next;
            pre=p;
            p=p->next;  //divide into two parts
        }
        pre->next=NULL;
        ListNode *lhalf=mergeSort(head);
        ListNode *rhalf=mergeSort(p);  //recursive
        return merge(lhalf, rhalf);   //merge
    }
    ListNode * merge(ListNode *lh, ListNode *rh){
        ListNode *temp=new ListNode(0);
        ListNode *p=temp;
        while(lh&&rh){
            if(lh->val<=rh->val){
                p->next=lh;
                lh=lh->next;
            }
            else{
                p->next=rh;
                rh=rh->next;
            }
            p=p->next;
        }
        if(!lh)
            p->next=rh;
        else
            p->next=lh;
        p=temp->next;
        temp->next=NULL;
        delete temp;
        return p;
    }
};

// Quick sort .from friend LDCheng 

/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */
class Solution {
    public: 
    ListNode *sortList(ListNode *head) {
        ListNode* newHead = new ListNode(INT_MIN);
        newHead->next = head;
        sortList2(newHead, NULL);
        head = newHead->next;
        delete newHead;
        return head;
    }

    void sortList2(ListNode* head, ListNode* end) {
        if (head == end || head->next == end || head->next->next == end) return;

        ListNode* split = head->next;
        head->next = head->next->next;

        ListNode* small = head;
        ListNode* pre = head;
        ListNode* ptr = head->next;

        while (ptr != end) {
            while (ptr!=end && ptr->val >= split->val) pre = ptr, ptr = ptr->next;
            if (ptr == end) break;
            if (small->next == ptr) small = ptr, pre = ptr, ptr = ptr->next;
            else {
                pre->next = ptr->next;
                ptr->next = small->next;
                small->next = ptr;

                small = ptr;
                ptr = pre->next;
            }
        }

        split->next = small->next;
        small->next = split;

        sortList2(head, split);
        sortList2(split, end);
    }
}; 


