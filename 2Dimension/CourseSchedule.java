/**
There are n different online courses numbered from 1 to n. Each course has some duration(course length) t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.

Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken. 


*/
public class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        PriorityQueue<Integer> queue = new PriorityQueue<>((a, b) -> b - a);

        int time = 0;
        for (int[] c: courses) {
            if(c[0] > c[1])   continue;
            if (time + c[0] <= c[1]) {
                queue.offer(c[0]);
                time += c[0];
            } else {
                if(!queue.isEmpty() && queue.peek() > c[0]){  // 替换后，可以保证堆中其他元素 都是满足条件的
                    time += c[0] - queue.poll();
                    queue.offer(c[0]);
                }
            }
        }

        return queue.size();
    }
}
