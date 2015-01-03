/**
 * Definition for Directed graph.
 * class DirectedGraphNode {
 *     int label;
 *     ArrayList<DirectedGraphNode> neighbors;
 *     DirectedGraphNode(int x) { label = x; neighbors = new ArrayList<DirectedGraphNode>(); }
 * };
 */
// http://lintcode.com/zh-cn/problem/topological-sorting/
public class Solution {
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */    
     Map<DirectedGraphNode,Integer> node2ind = null; 
    public DirectedGraphNode find(ArrayList<DirectedGraphNode> graph) {
        
        for(DirectedGraphNode node : graph) {
           if(node2ind.containsKey(node) && node2ind.get(node) == 0 ) {
                return node; 
            }    
        }
        
        return null; 
    }
    public void remove(DirectedGraphNode node){
        ArrayList<DirectedGraphNode> neighbors = node.neighbors;  
        for(DirectedGraphNode n : neighbors) {
            int cur = node2ind.get(n) ; 
            node2ind.put(n , cur-1) ; 
        }
        node2ind.remove(node) ; 
    }
    public ArrayList<DirectedGraphNode> topSort(ArrayList<DirectedGraphNode> graph) {
        // write your code here
        node2ind = new HashMap<DirectedGraphNode,Integer>() ; 
        for(DirectedGraphNode node : graph) {
            node2ind.put(node, 0) ; 
        }
        for(DirectedGraphNode node : graph) {
            ArrayList<DirectedGraphNode> neighbors = node.neighbors; 
            for( DirectedGraphNode nb : neighbors) {
                int cur = node2ind.get(nb) ; 
                node2ind.put(nb, cur+1) ; 
            }
        }
        
        
        
        DirectedGraphNode node = null; 
        ArrayList<DirectedGraphNode> ret = new  ArrayList<DirectedGraphNode>() ; 
        while ( (node = find(graph)) != null ) {
            ret.add(node) ; 
            remove( node) ; 
        }
        return ret; 
    }
}

