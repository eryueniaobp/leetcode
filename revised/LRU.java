import java.util.* ;
// Warn: the solution is buggy .Fix it later . 2015.1.16 
public class Solution {

    Node []cache = null;
    int capacity  = 0 ;
    int bckSize = 0 ;
    int size = 0 ;
    Node head = null ;
    Node tail = null;
    // @param capacity, an integer
    public Solution(int capacity) {
        // write your code here
        if(capacity <= 0 ) return ;
        bckSize = capacity*3 ;
        cache = new Node[bckSize] ;
        this.capacity = capacity ;
        this.size = 0 ;
    }
    protected int getPos(int key) {
        return key%bckSize ;
    }
    // @return an integer
    public int get(int key) {
        int pos = getPos(key) ;
        Node node = cache[pos] ;
        while(node!=null){
            if(node.key == key ) {
                refresh(node) ;
                return node.val ;
            }
            node = node.next ;
        }
        return -1;
        //   throw new RuntimeException("No Such Key") ;
    }
    public void refresh(Node node) {
        if(tail == node || tail == head ) {
            return ;
        }

        if(node == head ) {
            head = head.after ;
            tail.after = node ;
            node.after = null;
            node.before = tail  ;
        }else{
            // list.size >= 2 && node is not the head .
            Node prev = node.before ;
            prev.after = node.after ;
            if(node.after!=null) {
                node.after.before = prev ;
            }

            node.after = null;
            node.before = tail  ;
            tail.after = node;
        }
    }
    // @param key, an integer
    // @param value, an integer
    // @return nothing
    public void set(int key, int value) {
        // write your code here
        tryInvalidate() ;
        Node newone = new Node(key,value) ;
        int pos = getPos(key) ;
        Node node = cache[pos] ;
        if(node == null ) {
            cache[pos] = newone ;

        }else {
            while (node.next != null) {
                node = node.next;
            }
            node.next = newone ;
        }
        size++ ;

        if(head == null ) {
            head = newone ;
        }
        if(tail == null ) {
            tail = newone ;
        }else{
            tail.after= newone ;
            newone.before = tail ;
        }




    }
    public void tryInvalidate() {
        if(size == capacity - 1 ) {
            // remove head from cache .
            remove(head) ;
            // head.next = null;
            head = head.after  ;
            if(head!=null) head.before = null;
        }
    }
    public void remove(Node node){
        int k = node.key ;
        int pos =getPos(k) ;
        Node n = cache[pos] , prev = null;
        while(n!=null) {
            if(n.key == node.key) {
                if(prev == null ) {
                    cache[pos] = n.next ;
                }else{
                    prev.next = n.next ;
                }
                break;
            }
            prev = n ;
            n = n.next ;
        }
        size -- ;
    }
    public static class  Node {
        int key ;
        int val ;
        Node next = null ;
        Node before = null ;
        Node after  = null ;
        public Node(int key , int val) {
            this.key = key ;
            this.val  =val ;
        }

    }
    public static void main(String []args) {
        Solution sol = new Solution(2) ;
        sol.set(1,100) ;
        sol.set(2,-1) ;
        sol.get(2) ;
        sol.set(4,1) ;
        int val = sol.get(1) ;
        System.out.println(val);
    }
}

