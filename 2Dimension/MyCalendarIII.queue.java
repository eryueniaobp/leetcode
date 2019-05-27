package twoDimension;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;


public class MyCalendarThree {
    public static class Node{
        int s , e;
        public Node(int s, int e){
            this.s = s;
            this.e = e;
        }
    }


    List<Node> buf = new ArrayList<>();
    public MyCalendarThree(){

    }
    public int book(int start, int end) {

        buf.add(new Node(start, end));
        Collections.sort(buf, (o1, o2) -> {return o1.s - o2.s ; });

        PriorityQueue<Node> q = new PriorityQueue<>((o1, o2) -> { return o1.e - o2.e ; });

        int k = 0 ;
        for(Node node : buf) {
            start = node.s ;
            end = node.e  ;

            if (q.isEmpty()) {
                q.add(new Node(start, end));
            } else {
                if (q.peek().e <= start) {
                    q.poll();
                }
                q.add(new Node(start, end));

            }
            k = Math.max(k , q.size());
        }

        return k ;
    }

    public static void main(String[] args) {
        MyCalendarThree cal = new MyCalendarThree();
        cal.book(10, 12);
        int k = cal.book(11, 13);

        System.out.println(k);

    }
}
