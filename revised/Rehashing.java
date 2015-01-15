/**
 * Definition for ListNode
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
/**
The size of the hash table is not determinate at the very beginning. If the total size of keys is too large (e.g. size >= capacity / 10), we should double the size of the hash table and rehash every keys. Say you have a hash table looks like below:

size=3, capacity=4
[null, 21->9->null, 14->null, null]

The hash function is:

int hashcode(int key, int capacity) {
    return key % capacity;
}

here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same hashcode 1 (21 % 4 = 9 % 4 = 1). We store them in the hash table by linked list.
*/
public class Solution {
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    ListNode []ret = null ; 
    public ListNode[] rehashing(ListNode[] hashTable) {
        int len  = hashTable.length ; 
        ret = new ListNode[len + len] ; 
        for(ListNode n :hashTable) {
            while(n!=null) {
                add(n) ; 
                n = n.next ; 
            }
        }
        return ret; 
    }
    protected void add(ListNode node ) {
        if(node == null ) return  ; 
        int size  = ret.length ; 
        int pos = (node.val%size + size)%size ; 
        ListNode cur = ret[pos] ,prev = null; 
        while(cur!=null){
            prev =cur ; 
            cur = cur.next ; 
        }
        if(prev!=null) prev.next = new ListNode(node.val) ;  // deep clone. make the structure clear
        else{
            ret[pos] = new ListNode(node.val) ; 
        }
    }
};


