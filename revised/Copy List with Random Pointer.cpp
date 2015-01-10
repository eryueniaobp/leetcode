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
/* A more clear solution */
/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    public RandomListNode copyRandomList(RandomListNode head) {
        Map<RandomListNode,RandomListNode> r2c = new HashMap<RandomListNode,RandomListNode>(); 
        if(head == null ) return null ; 
        
        RandomListNode node = head ; 
        RandomListNode prev = null; 
        while(node!=null) {
            if(!r2c.containsKey(node)) {
                RandomListNode cn = new RandomListNode(node.label) ; 
                r2c.put(node,cn) ; 
            }else{
                
            }
            if(node.random!=null && !r2c.containsKey(node.random)) {
                RandomListNode cr = new RandomListNode(node.random.label) ;
                r2c.put(node.random,cr) ; 
            }
            // always use the Map r2c to get the new node             
            if(prev != null ) {
                prev.next = r2c.get(node) ;
                prev = prev.next ; 
                prev.random = node.random==null?null:r2c.get(node.random) ; 
            }else{
                prev = r2c.get(node) ; 
                prev.random = node.random==null?null:r2c.get(node.random) ; 
            }
            node = node.next ; 
        }
        
        return r2c.get(head) ; 
        
    }
}


