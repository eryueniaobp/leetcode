package graph;

import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 最大流算法.
 * 增广路径.
 * https://blog.csdn.net/qq_41357771/article/details/79416899
 *
 */
public class EdmondsKarp {
    public int solve(int [][]graph, int s , int t){
        Queue<Integer> bfs = new LinkedList<>();

        int ret = 0 ;
        int N = graph.length ;
        int [][]flow = new int[N][N];  // flow = 0
        //不断的进行bfs即可.
        while(true){
            int []a = new int[N];

            int []p = new int[N] ; //parent-node :  p->cur
            bfs.add(s);
            a[s] = Integer.MAX_VALUE ;  // a[idx] 当前bfs时 到 idx的最大流.

            // bfs
            while(!bfs.isEmpty()){
                int x  = bfs.poll();

                for(int i = 0 ; i< N ;i++){
                    if( a[i] == 0  && graph[x][i] > flow[x][i]){
                        bfs.add(i);
                        a[i] = Math.min(a[x] , graph[x][i] - flow[x][i]) ;
                        p[i] = x ;
                    }
                }
                if(a[t] > 0) { // 可能是 负数么.
                    bfs.clear();
                    break;
                }
            }
            if(a[t] == 0){
                break ;  // no augment path .
            }

            // 这里进行流量修改.

            for(int u = t ; u!=s; u = p[u]){
                flow[ p[u] ][u] += a[t] ;
                flow[u][p[u]] -= a[t] ;
            }
            ret += a[t];


        }
        return ret;
    }
    public static void main(String []argv){
        int [][]graph = {
                {0, 16, 0, 13 , 0 , 0  }, // A0
                {0, 0, 12, 10, 0 , 0 }, // A1
                {0,0, 0, 9, 0, 20} ,  // A2
                {0, 4, 0, 0, 14, 0} ,  //A3
                {0,0,7,0, 0, 4} ,  // A4
                {0, 0, 0, 0, 0, 0} // A5
        };
        EdmondsKarp ek = new EdmondsKarp();
        int flow = ek.solve(graph, 0, 5 ) ;
        // max flow = 23
        System.out.println("max flow = " + flow );

    }
}
