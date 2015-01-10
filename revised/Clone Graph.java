/**
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*/
public class Solution {
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    public UndirectedGraphNode clone(UndirectedGraphNode node) {
        UndirectedGraphNode root = new UndirectedGraphNode(node.label) ;
        raw2new.put(node ,root) ;
        return root ; 
    }
    
    Map<UndirectedGraphNode,UndirectedGraphNode> raw2new = null ;
    Queue<UndirectedGraphNode> q = null ;
    
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node == null ) return null; 
        q = new LinkedList<UndirectedGraphNode>() ; 
        raw2new = new HashMap<UndirectedGraphNode,UndirectedGraphNode>() ;

        UndirectedGraphNode root = clone(node);
        q.offer(node) ; 
        while(!q.isEmpty()){
            UndirectedGraphNode cur  = q.poll() ;
            UndirectedGraphNode clone = raw2new.get(cur) ; 
            
            for(UndirectedGraphNode nb : cur.neighbors){
             
                if(!raw2new.containsKey(nb)) {
                    UndirectedGraphNode cnb = clone(nb) ; 
                    clone.neighbors.add(cnb) ;
                    q.offer(nb) ; 
                }else{
                    UndirectedGraphNode cnb = raw2new.get(nb) ;
                    clone.neighbors.add(cnb) ; 
                }
            }
        }
        return root; 
    }
}
