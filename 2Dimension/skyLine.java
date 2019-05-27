package twoDimension;

import java.util.*;
public class SkyLine {


    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> resList = new ArrayList<>();
        if(buildings == null || buildings.length == 0){
            return resList;
        }
        PriorityQueue<Point> queue = new PriorityQueue<>( (o1, o2) -> {
            if (o1.pos != o2.pos) {
                return o1.pos -o2.pos ;
            }
            return o1.height - o2.height ;
        });
        for( int i = 0 ; i < buildings.length; i++){
            queue.offer(new Point(buildings[i][0], -buildings[i][2]));
            queue.offer(new Point(buildings[i][1], buildings[i][2]));

        }
        PriorityQueue<Integer> maxHeightQueue = new PriorityQueue<>(Comparator.reverseOrder());
        maxHeightQueue.offer(0);

        int prePeak = maxHeightQueue.peek();
        while(!queue.isEmpty()){
            Point point = queue.poll();
            if (point.height < 0) {
                maxHeightQueue.offer(-point.height);
            }else{
                maxHeightQueue.remove(point.height);  // right edge?
            }
            int curPeak = maxHeightQueue.peek();
            if(curPeak != prePeak){
                resList.add(Arrays.asList(new Integer[]{point.pos,curPeak}));
            }
        }
        return resList ;
    }
    public static class Point{
        int pos, height;
        public Point(int pos, int height){
            this.pos = pos;
            this.height = height ;
        }
    }

    public static void main(String[] args) {
//        [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
        int [][]buildings = {


                {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}

        };
        SkyLine skyline = new SkyLine();
        List<List<Integer>> ret = skyline.getSkyline(buildings);
        for(List<Integer> ps : ret ){
            System.out.println(ps.get(0) + "\t" + ps.get(1));
        }
    }
}
