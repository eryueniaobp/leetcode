package twoDimension;


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class MeetingRoom {
    public static class Node{
        int s , e;
        public Node(int s, int e){
            this.s = s;
            this.e = e;
        }
    }
    public MeetingRoom(){

    }
    public int getMeetingRoom(List<Node>  meetings){
        Collections.sort(meetings, (o1, o2) -> {return o1.s - o2.s; });
        PriorityQueue<Node> q = new PriorityQueue<>((o1, o2) -> { return o1.e - o2.e ; });
        int k = 0 ;
        for(Node m : meetings){
            if( q.isEmpty() ){
                q.add(m);
            }else{
                if(q.peek().e <= m.s ){
                    q.poll();
                    q.add(m);
                }else{
                    q.add(m);
                }
            }

            k = Math.max(k,  q.size());
        }
        return k ;



    }
    public static void main(String[] args) {
        List<Node> meetings = new ArrayList<>();
        meetings.add(new Node(1, 20 ));
        meetings.add(new Node(2, 30 ));
        meetings.add(new Node(3, 10 ));
        meetings.add(new Node(21, 40 ));


        MeetingRoom room = new MeetingRoom();
        int k = room.getMeetingRoom(meetings);
        System.out.println(k);
    }
}
