package graph;

import java.util.LinkedList;
import java.util.Queue;


public class Maze {
    /**
     * graph
     * @param graph
     * @return
     */
    public boolean solve(int [][]graph, int M , int N ){ // M * N
        int [][]mask = graph.clone();

        Queue<Node> bfs = new LinkedList<>();
        bfs.add(Node.it(0,0));
        while(!bfs.isEmpty()){
            Node node = bfs.poll();
            if(checkAndAdd(node.x -1 , node.y , bfs , M,N ,mask)
                ||  checkAndAdd(node.x +1 , node.y , bfs , M,N ,mask)
                || checkAndAdd(node.x  , node.y -1, bfs , M,N ,mask)
                || checkAndAdd(node.x  , node.y +1, bfs , M,N ,mask)) {
                return true ;
            }
        }
        return false;
    }
    public boolean checkAndAdd(int x, int y, Queue<Node> bfs, int M, int N, int [][]mask ){
        if(x >= 0 && x < N && y>=0 && y< M && mask[x][y] ==0){
            bfs.add(Node.it(x, y ));
            mask[x][y] = 1;
            if(x == M-1 && y == N-1) return true;
        }
        return false;

    }
    public static void main(String []argv){
        int [][]graph = {
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 0, 0, 1},
                {1, 0, 1, 0}
        };
        Maze maze = new Maze() ;
        boolean ok = maze.solve(graph, graph.length, graph[0].length);
        System.out.println(ok);
    }
    public static class Node{
        int x, y ;
        public Node(int x, int y){
            this.x = x;
            this.y = y ;

        }

        public static Node it(int x, int y){
            return new Node(x, y);
        }

    }
}


