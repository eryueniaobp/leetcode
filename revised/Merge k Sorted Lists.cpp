/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * O(k+ nlogk) , n是全部元素的个数,每次调整堆需要  log k时间，建堆 k 
 */
struct Node{
    int val;
    int pos;
    bool operator < (const Node& a ) const {
        return val > a.val;
    }
    Node(int v,int p):val(v),pos(p){}
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * head = NULL , *cur=NULL,*pre = NULL; 
        vector<Node> vheap;
        for(int i = 0 ;i<lists.size() ; i ++ ) {
            if(lists[i] != NULL ) {
                vheap.push_back(Node(lists[i]->val,i));
            }
        }
        make_heap(vheap.begin(),vheap.end());
        while(vheap.size() > 0 ){
            Node node = vheap.front();
            lists[node.pos] = lists[node.pos]->next;
            pop_heap(vheap.begin(),vheap.end());
            vheap.pop_back();
            if(lists[node.pos] != NULL ) {
                vheap.push_back(Node(lists[node.pos]->val,node.pos));
                push_heap(vheap.begin(),vheap.end());
            }
            if(head == NULL){
                head = new ListNode(node.val);
                pre = head;
            }else{
                cur = new ListNode(node.val);
                pre->next = cur;
                pre = cur;
            }
        }
        return head;
    }
};


