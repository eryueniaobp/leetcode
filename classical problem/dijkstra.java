import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;


public class Dijkstra {

    /**
     *
     * @param graph
     * @param source
     * @return source 到每一个 点的最短距离.
     */
    public Node[] solve(int [][]graph, int source){
        assert  source < graph.length ;
        int N = graph.length ;
        Node []ret = new Node[graph.length];

        int []dist = new int[graph.length];
        int []visited = new int[graph.length] ;


        for(int i = 0 ; i< N ; i++) {
            visited[i] =  0 ;
            dist[i] = Integer.MAX_VALUE;
        }

        PriorityQueue<Node> queue = new PriorityQueue<Node>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.dist - o2.dist ;
            }
        });

        dist[source] = 0 ;
        queue.add(Node.it(source, null, 0 ));

        List<Node> solved = new ArrayList<>();

//        solved.add(source);
//        ret[source] = 0  ;

        while(solved.size() < graph.length){

            Node node = queue.poll();
            if(visited[node.idx] == 1) {
                continue;
            }
            visited[node.idx] = 1 ;  // visited.
            solved.add(node);


            for(int i =  0 ; i< N ; i++){
                if(node.idx != i && visited[i] == 0 &&  node.dist + graph[node.idx][i] < dist[i] ) {
                    queue.add(Node.it(i ,  node,   node.dist + graph[node.idx][i])) ;
                    dist[i] = node.dist + graph[node.idx][i] ;
                }
            }



        }
        for(Node node: solved){
            ret[node.idx] = node;
        }
        for(int i = 0 ;i < N  ;i ++){
            System.out.println(String.format("%s -> %s : %s", source , i , dist[i]));
        }
        return ret ;

    }

    public static class Node {
        int idx ;
        Node parent ;
        int dist ;
        public Node(int idx, Node parent, int dist){
            this.idx = idx ;
            this.parent = parent;
            this.dist = dist ;
        }
        public static Node it(int idx, Node parent, int dist){
            return new Node(idx, parent, dist);
        }
        public String path(){
            StringBuilder sb = new StringBuilder();
            sb.append(this.idx);


            Node it = this.parent;
            while(it != null){
                sb.append(String.format("<- %s", it.idx));
                it = it.parent;
            }
            return sb.toString();
        }
    }


    public static void main(String []argv){
        int [][]graph = {
                {1,10,30 },
                {3,4, 5},
                {8,1, 100}
        };
        Dijkstra sol = new Dijkstra();

        Node []ret =  sol.solve(graph , 1);
        for(int i = 0 ;i<ret.length ; i++){
            System.out.println(ret[i].dist + "\t" + ret[i].path());
        }

    }
}
