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
public class Solution {
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    public ListNode partition(ListNode head, int x) {
        ListNode ltail = null ,lhead = null;
        ListNode rtail = null, rhead = null ;  
        while(head!=null){
            if(head.val < x ) {
                if(ltail == null) { ltail = head ; lhead = head ; } 
                else{
                    ltail.next = head ;
                    ltail = head ; 
                }
            }else{
                if(rtail ==null) { rtail = head ; rhead = head ; } 
                else{
                    rtail.next = head ; 
                    rtail = head ; 
                }
            }
            head = head.next ; 
        }
        if(ltail != null) ltail.next =rhead ;
        // Note : must keep the rtail.next = null .or else maybe a self-cycle list .
        if(rtail!=null ) rtail.next= null; 
        return lhead != null?lhead:rhead; 
        
    }
}


